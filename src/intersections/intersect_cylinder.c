/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:54:54 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/28 13:44:51 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	calculate_abcd(t_operation *op, t_cylinder *cy, t_vec3 dir, t_vec3 cyo)
{
	double	a;
	double	b;
	double	c;

	a = dot_product(&dir, &dir);
	b = pow(dot_product(&dir, &cy->normal), 2);
	op->A = a - b;
	a = dot_product(&dir, &cyo);
	b = dot_product(&dir, &cy->normal);
	c = dot_product(&cyo, &cy->normal);
	op->B = 2 * (a - b * c);
	a = dot_product(&cyo, &cyo);
	b = pow(dot_product(&cyo, &cy->normal), 2);
	c = pow(cy->radius, 2);
	op->C = a - b - c;
	op->delta = op->B * op->B - 4 * op->A * op->C;
	if (op->delta < 0)
		return (1);
	return (0);
}

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

t_vec3	get_cyl_normal(t_vec3 hp, t_cylinder *cy, double m)
{
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;

	a = scalar_mult(cy->normal, m);
	b = add_vec3(cy->pos, a);
	c = substract_vec3(hp, b);
	return (unit_vec3(c));
}

int	check_interaction(t_ray *ray, t_operation op, t_cylinder *cy, int i)
{
	t_vec3	hp;
	double	a;
	double	b;
	double	m;

	if (op.t[i] > 0)
	{
		hp = add_vec3(op.tri.origin, scalar_mult(op.tri.dir, op.t[i]));
		a = dot_product(&op.tri.dir, &cy->normal);
		b = dot_product(&op.tri.co, &cy->normal);
		m = a * op.t[i] + b;
		if (m >= 0 && m <= cy->height)
		{
			ray->hit = true;
			ray->distance = op.t[i];
			ray->hit_point = hp;
			ray->normal = get_cyl_normal(hp, cy, m);
			return (1);
		}
	}
	return (0);
}

t_ray	hit_cylinder(t_vec3 dir, t_vec3 origin, t_cylinder *cy)
{
	t_ray		ray;
	t_operation	op;
	int			i;

	ray.hit = false;
	ray.distance = INFINITY;
	op.tri.dir = dir;
	op.tri.origin = origin;
	op.tri.co = substract_vec3(cy->pos, origin);
	if (calculate_abcd(&op, cy, dir, op.tri.co))
		return (ray);
	calculate_t(&op);
	i = 0;
	while (i < 2)
	{
		if (check_interaction(&ray, op, cy, i))
			return (ray);
		i++;
	}
	return (ray);
}
