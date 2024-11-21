/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:51:00 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/21 17:28:49 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	calculate_t(t_operation *op)
{
	double	tmp;

	op->t[0] = (-op->B - sqrt(op->delta)) / (2 * op->A);
	op->t[1] = (-op->B + sqrt(op->delta)) / (2 * op->A);
	if (op->t[0] > op->t[1])
	{
		tmp = op->t[0];
		op->t[0] = op->t[1];
		op->t[1] = tmp;
	}
}

int	calculate_abcd_cone(t_operation *op, t_cone *co, t_vec3 dir, t_vec3 con)
{
	double	a;
	double	b;
	double	c;
	double	k;

	k = pow(co->radius / co->height, 2);
	a = dot_product(&dir, &dir);
	b = pow(dot_product(&dir, &co->normal), 2);
	op->A = a - (1 + k) * b;
	a = dot_product(&dir, &con);
	b = dot_product(&dir, &co->normal);
	c = dot_product(&con, &co->normal);
	op->B = 2 * a - (1 + k) * b * c;
	a = dot_product(&con, &con);
	b = pow(dot_product(&con, &co->normal), 2);
	op->C = a - (1 + k) * b;
	op->delta = op->B * op->B - 4 * op->A * op->C;
	if (op->delta < 0)
		return (1);
	return (0);
}

t_vec3	get_cone_normal(t_vec3 hp, t_cone *co, double m)
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;
	t_vec3	adjusted_normal;
	double	k;

	a = scalar_mult(co->normal, m);
	b = add_vec3(co->pos, a);
	c = substract_vec3(hp, b);
	adjusted_normal = unit_vec3(c);
	k = co->radius / co->height;
	a = scalar_mult(co->normal, k);
	adjusted_normal = substract_vec3(adjusted_normal, a);
	return (unit_vec3(adjusted_normal));
}

int	check_interaction_cone(t_ray *ray, t_operation op, t_cone *co, int i)
{
	t_vec3	hp;
	double	a;
	double	b;
	double	m;

	if (op.t[i] > 0)
	{
		hp = add_vec3(op.tri.origin, scalar_mult(op.tri.dir, op.t[i]));
		a = dot_product(&op.tri.dir, &co->normal);
		b = dot_product(&op.tri.co, &co->normal);
		m = a * op.t[i] + b;
		if (m >= 0 && m <= co->height)
		{
			ray->hit = true;
			ray->distance = op.t[i];
			ray->hit_point = hp;
			ray->normal = get_cone_normal(hp, co, m);
			return (1);
		}
	}
	return (0);
}

t_ray	hit_cone(t_vec3 dir, t_vec3 origin, t_cone *co)
{
	t_ray		ray;
	t_operation	op;
	int			i;

	ray.hit = false;
	ray.distance = INFINITY;
	op.tri.dir = dir;
	op.tri.origin = origin;
	op.tri.co = substract_vec3(co->pos, origin);
	if (calculate_abcd_cone(&op, co, dir, op.tri.co))
		return (ray);
	calculate_t(&op);
	i = 0;
	while (i < 2)
	{
		if (check_interaction_cone(&ray, op, co, i))
			return (ray);
		i++;
	}
	return (ray);
}

/*

t_ray hit_cone(t_vec3 direction, t_vec3 origin, t_cone *co)
{
    t_ray ray;
    t_operation op;
    t_vec3 cone_to_origin;
    double lambda;
    double projection;

    ft_bzero(&ray, sizeof(t_ray));
    ray.hit = false;

    // Vector desde el vértice del cono al origen del rayo
    cone_to_origin = substract_vec3(origin, co->pos);

    // Coeficientes cuadráticos para el cuerpo del cono
    double dir_dot_normal = dot_product(&direction, &co->normal);
    double origin_dot_normal = dot_product(&cone_to_origin, &co->normal);

    op.A = dot_product(&direction, &direction) 
	- (1 + co->tan_squared) * pow(dir_dot_normal, 2);
    op.B = 2 * (dot_product(&direction, &cone_to_origin) 
	- (1 + co->tan_squared) * dir_dot_normal * origin_dot_normal);
    op.C = dot_product(&cone_to_origin, &cone_to_origin) 
	- (1 + co->tan_squared) * pow(origin_dot_normal, 2);

    // Discriminante
    op.delta = op.B * op.B - 4 * op.A * op.C;

    if (op.delta >= 0)
    {
        // Resolviendo la ecuación cuadrática para encontrar "lambda"
        lambda = calculate_quadratic_root(op);
        if (lambda > 0)
        {
            // Calcula el punto de impacto en el cuerpo del cono
            ray.hit_point = add_vec3(origin, scalar_mult(direction, lambda));
            t_vec3 hit_to_vertex = substract_vec3(ray.hit_point, co->pos);

            // Proyección del punto de impacto sobre el eje del cono
            projection = dot_product(&hit_to_vertex, &co->normal);

            // Verificar si el impacto está dentro de la altura del cono
            if (projection >= 0 && projection <= co->height)
            {
                ray.hit = true;
                ray.distance = lambda;
            }
        }
    }

    // Verificar si el rayo impacta la base del cono
    t_vec3 base_center = co->base_center;
    double d = dot_product(&co->normal, &direction);

    if (fabs(d) > 1e-6) // Asegúrate de que el rayo no sea paralelo a la base
    {
        t_vec3 v = substract_vec3(base_center, origin);
        double t_cap = dot_product(&co->normal, &v) / d;

        if (t_cap > 0)
        {
            t_vec3 cap_hit_point = add_vec3(origin, 
			scalar_mult(direction, t_cap));

            // Verifica si el punto de impacto está dentro del radio de la base
            if (euclidean_distance(base_center, cap_hit_point) 
				<= pow(co->radius, 2))
            {
                // Actualiza si es más cercano
                if (!ray.hit || t_cap < ray.distance)
                {
                    ray.hit = true;
                    ray.distance = t_cap;
                    ray.hit_point = cap_hit_point;
                }
            }
        }
    }

    return ray;
}*/
