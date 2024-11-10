/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:51:00 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/10 12:20:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

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
	adjusted_normal = substract_vec3(adjusted_normal,
			scalar_mult(co->normal, k));
	return (unit_vec3(adjusted_normal));
}

void	check_interaction_cone(t_ray *ray, t_operation op, t_cone *co)
{
	t_vec3	hp;
	double	a;
	double	b;
	double	m;

	if (op.lambda > 0)
	{
		hp = add_vec3(op.tri.origin, scalar_mult(op.tri.dir, op.lambda));
		a = dot_product(&op.tri.dir, &co->normal);
		b = dot_product(&op.tri.co, &co->normal);
		m = a * op.lambda + b;
		if (m >= 0 && m <= co->height)
		{
			ray->hit = true;
			ray->distance = op.lambda;
			ray->hit_point = hp;
			ray->normal = get_cone_normal(hp, co, m);
		}
	}
}

t_ray	hit_cone(t_vec3 dir, t_vec3 origin, t_cone *co)
{
	t_ray		ray;
	t_operation	op;

	ft_bzero(&ray, (sizeof(t_ray)));
	ft_bzero(&op, (sizeof(t_operation)));
	ray.hit = false;
	ray.distance = INFINITY;
	op.tri.dir = dir;
	op.tri.origin = origin;
	op.tri.co = substract_vec3(co->pos, origin);
	if (calculate_abcd_cone(&op, co, dir, op.tri.co))
		return (ray);
	op.lambda = calculate_quadratic_root(op);
	check_interaction_cone(&ray, op, co);
	return (ray);
}
