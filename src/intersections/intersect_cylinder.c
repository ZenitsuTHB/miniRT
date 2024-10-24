/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:54:54 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/24 12:45:27 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static double	ft_quadratic(t_operation op)
{
	double	sqrted;
	
	if (!op.delta)
		return (-op.B / (2.0 * op.A));
	sqrted = sqrt(op.delta);
	op.t[0] = (-op.B - sqrted) / (2.0 * op.A);
	op.t[1] = (-op.B + sqrted) / (2.0 * op.A);
	if (op.t[0] >= 0 && op.t[0] < op.t[1])
		return (op.t[0]);
	else if (op.t[1] >= 0)
		return (op.t[1]);
	return (-1);
}

t_ray	hit_cylinder(t_vec3 dir, t_vec3 origin, t_cylinder *cy)
{
	t_ray		ray;
	t_operation	op;

	ray.hit = false;
	op.OC = substract_vec3(cy->pos, origin);
	op.A = dot_product(&dir, &dir);
	op.B = dot_product(&op.OC, &dir);
	op.C = dot_product(&op.OC, &op.OC) - (cy->radius * cy->radius);
	op.delta = (op.B * op.B) - (op.A * op.C);
	if (op.delta < 0)
		return (ray);
	ray.distance = ft_quadratic(op);
	if (ray.distance < 0)
		return (ray);
	ray.hit_point = add_vec3(origin, scalar_mult(dir, ray.distance));
	ray.normal = unit_vec3(substract_vec3(dir, cy->pos));
	ray.hit = true;
	return (ray);
}

/*
t_vec3	ray_at(t_ray *ray, double t)
{
	t_vec3	normal;

	normal  = ray->normal;
	scalar_mult(normal, t);
	return (add_vec3(ray->origin, normal));
}

t_vec3	calculate_normal(t_cylinder *cy, t_vec3 p)
{
	t_vec3	tmp;
	t_vec3	tmp2;
	t_vec3	normal;

	tmp = substract_vec3(cy->pos, p);
	tmp2 = scalar_mult(cy->normal, dot_product(&tmp, &cy->normal));
	normal = substract_vec3(tmp2, tmp);
	return (unit_vec3(normal));
}

bool	calc_hit_cyl(t_ray *ray, t_operation op, t_cylinder *cy)
{
	double	proj;
	double	root;
	t_vec3	tmp;

	root = (-op.B - sqrt(op.delta)) / op.A;
	if (root <= op.t[0] || root >= op.t[1])
	{
		root = (-op.B + sqrt(op.delta)) / op.A;
		if (root <= op.t[0] || root >= op.t[1])\
			return (false);
	}
	tmp = ray_at(ray, root);
	tmp = substract_vec3(tmp, cy->pos);
	proj = dot_product(&cy->normal, &tmp);
	if (proj < 0 || proj > cy->height)
		return (false);
	ray->distance = root;
	ray->hit_point = ray_at(ray, root);
	ray->normal = calculate_normal(cy, ray->hit_point);
	return (true);
}

bool	hit_body_cyl(t_ray *ray, t_operation op, t_cylinder *cy)
{
	t_vec3	tmp;
	t_vec3	dp;
	t_vec3	ocp;

	op.OC = substract_vec3(ray->origin, cy->pos);
	tmp = scalar_mult(cy->normal, dot_product(&ray->normal, &cy->normal));
	dp = substract_vec3(ray->normal, tmp);
	tmp = scalar_mult(cy->normal, dot_product(&op.OC, &cy->normal));
	ocp = substract_vec3(op.OC, tmp);
	op.A = dot_product(&dp, &dp);
	op.B = dot_product(&ocp, &dp);
	op.C = dot_product(&ocp, &ocp) - cy->radius * cy->radius;
	op.delta = op.B * op.B - op.A * op.C;
	if (op.delta < 0)
		return (false);
	return (calc_hit_cyl(ray, op, cy));
}

t_ray	hit_cylinder(t_vec3 dir, t_vec3 origin, t_cylinder *cy)
{
	t_ray		ray;
	t_operation	op;

	ray.normal = dir;
	ray.origin = origin;
	op.t[0] = 0.001;
	op.t[1] = INFINITY;
	if (hit_body_cyl(&ray, op, cy))
	{
		ray.hit = true;
		return (ray);
	}
	ray.hit = false;
	return (ray);
}
*/
