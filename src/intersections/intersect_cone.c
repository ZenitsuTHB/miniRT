/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:51:00 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/02 13:51:57 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "../../include/minirt.h"

int	calculate_abc(t_operation *op, t_cone *co, t_vec3 dir, t_vec3 cyo)
{
	double	a;
	double	b;
	double	c;

	a = dot_product(&dir, &dir);
	b = pow(dot_product(&dir, &co->normal), 2);
	op->A = a - b;
	a = dot_product(&dir, &cyo);
	b = dot_product(&dir, &co->normal);
	c = dot_product(&cyo, &co->normal);
	op->B = 2 * (a - b * c);
	a = dot_product(&cyo, &cyo);
	b = pow(dot_product(&cyo, &co->normal), 2);
	c = pow(co->radius, 2);
	op->C = a - b - c;
	op->delta = op->B * op->B - 4 * op->A * op->C;
	if (op->delta < 0)
		return (1);
	return (0);
}

void	calculate_ttt(t_operation *op)
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

t_vec3	get_cone_normal(t_vec3 hp, t_cone *co, double m)
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;

	a = scalar_mult(co->normal, m);
	b = add_vec3(co->pos, a);
	c = substract_vec3(hp, b);
	return (unit_vec3(c));
}

int	check_interactions(t_ray *ray, t_operation op, t_cone *co, int i)
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
	if (calculate_abc(&op, co, dir, op.tri.co))
		return (ray);
	calculate_ttt(&op);
	i = 0;
	while (i < 2)
	{
		if (check_interactions(&ray, op, co, i))
			return (ray);
		i++;
	}
	return (ray);
}
*/
#include "../../include/minirt.h"

int	calculate_abcd_cone(t_operation *op, t_cone *cone, t_vec3 dir, t_vec3 co)
{
	double	a;
	double	b;
	double	c;
	double	k;

	// Factor de apertura del cono
	k = pow(cone->radius / cone->height, 2);

	// Calculamos los coeficientes A, B y C basados en la geometría del cono
	a = dot_product(&dir, &dir) - (1 + k) * pow(dot_product(&dir, &cone->normal), 2);
	b = dot_product(&dir, &co) - (1 + k) * dot_product(&dir, &cone->normal) * dot_product(&co, &cone->normal);
	op->A = a;
	op->B = 2 * b;
	c = dot_product(&co, &co) - (1 + k) * pow(dot_product(&co, &cone->normal), 2);
	op->C = c;

	// Calcular el discriminante (delta)
	op->delta = op->B * op->B - 4 * op->A * op->C;
	if (op->delta < 0)
		return (1);
	return (0);
}

t_vec3	get_cone_normal(t_vec3 hp, t_cone *cone, double m)
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;

	// Calcular el punto en el eje del cono
	a = scalar_mult(cone->normal, m);
	b = add_vec3(cone->pos, a);
	c = substract_vec3(hp, b);

	// Ajustar la normal del cono
	t_vec3 adjusted_normal = unit_vec3(c);
	double k = cone->radius / cone->height;
	adjusted_normal = substract_vec3(adjusted_normal, scalar_mult(cone->normal, k));

	return unit_vec3(adjusted_normal);
}

int	check_interaction_cone(t_ray *ray, t_operation op, t_cone *cone, int i)
{
	t_vec3	hp;
	double	a;
	double	b;
	double	m;

	if (op.t[i] > 0)
	{
		// Calcular el punto de intersección
		hp = add_vec3(op.tri.origin, scalar_mult(op.tri.dir, op.t[i]));

		// Calcular m para verificar si está dentro de los límites del cono
		a = dot_product(&op.tri.dir, &cone->normal);
		b = dot_product(&op.tri.co, &cone->normal);
		m = a * op.t[i] + b;
		if (m >= 0 && m <= cone->height)
		{
			ray->hit = true;
			ray->distance = op.t[i];
			ray->hit_point = hp;
			ray->normal = get_cone_normal(hp, cone, m);
			return (1);
		}
	}
	return (0);
}

t_ray	hit_cone(t_vec3 dir, t_vec3 origin, t_cone *cone)
{
	t_ray		ray;
	t_operation	op;
	int			i;

	ray.hit = false;
	ray.distance = INFINITY;
	op.tri.dir = dir;
	op.tri.origin = origin;
	op.tri.co = substract_vec3(cone->pos, origin);

	// Calcular los coeficientes A, B, y C para el cono
	if (calculate_abcd_cone(&op, cone, dir, op.tri.co))
		return (ray);

	// Calcular los valores de t
	calculate_t(&op);

	// Verificar las posibles intersecciones
	i = 0;
	while (i < 2)
	{
		if (check_interaction_cone(&ray, op, cone, i))
			return (ray);
		i++;
	}
	return (ray);
}
