/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:51:00 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/21 18:49:23 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	calculate_t(t_operation *op)
{
	double	tmp;

	op->t[0] = (-op->b - sqrt(op->delta)) / (2 * op->a);
	op->t[1] = (-op->b + sqrt(op->delta)) / (2 * op->a);
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
	op->a = a - (1 + k) * b;
	a = dot_product(&dir, &con);
	b = dot_product(&dir, &co->normal);
	c = dot_product(&con, &co->normal);
	op->b = 2 * a - (1 + k) * b * c;
	a = dot_product(&con, &con);
	b = pow(dot_product(&con, &co->normal), 2);
	op->c = a - (1 + k) * b;
	op->delta = op->b * op->b - 4 * op->a * op->c;
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
