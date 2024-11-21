/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:54:54 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/21 18:21:45 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

bool	check_cap(t_triplevec tri, t_cylinder *cy, double *t_cap, t_vec3 *chp)
{
	double	d;
	t_vec3	v;
	double	t;
	t_vec3	point_on_plane;
	t_vec3	to_center;

	d = dot_product(&cy->normal, &tri.dir);
	if (fabs(d) > 1e-6)
	{
		v = substract_vec3(tri.co, tri.origin);
		t = dot_product(&cy->normal, &v) / d;
		if (t > 0)
		{
			point_on_plane = add_vec3(tri.origin, scalar_mult(tri.dir, t));
			to_center = substract_vec3(point_on_plane, tri.co);
			if (dot_product(&to_center, &to_center) <= cy->radius * cy->radius)
			{
				*t_cap = t;
				*chp = point_on_plane;
				return (true);
			}
		}
	}
	return (false);
}

bool	check_cylinder_caps(t_triplevec duo, t_cylinder *cy,
		double *t_cap, t_vec3 *cap_hit_point)
{
	duo.co = cy->pos;
	if (check_cap(duo, cy, t_cap, cap_hit_point))
		return (true);
	duo.co = add_vec3(cy->pos, scalar_mult(cy->normal, cy->height));
	return (check_cap(duo, cy, t_cap, cap_hit_point));
}

void	get_abcd_cyl(t_cylinder *cy, t_vec3 origin, t_vec3 dir, t_operation *op)
{
	t_vec3	cy_to_ray_origin;
	double	cy_dot_dir;
	double	cy_dot_origin;
	double	tmp;

	cy_to_ray_origin = substract_vec3(origin, cy->pos);
	cy_dot_dir = dot_product(&dir, &cy->normal);
	cy_dot_origin = dot_product(&cy_to_ray_origin, &cy->normal);
	op->A = dot_product(&dir, &dir) - cy_dot_dir * cy_dot_dir;
	tmp = dot_product(&dir, &cy_to_ray_origin);
	op->B = 2 * (tmp - cy_dot_dir * cy_dot_origin);
	tmp = dot_product(&cy_to_ray_origin, &cy_to_ray_origin);
	op->C = tmp - cy_dot_origin * cy_dot_origin - pow(cy->radius, 2);
	op->delta = op->B * op->B - 4 * op->A * op->C;
}

t_ray	hit_cyl_body(t_vec3 dir, t_vec3 origin, t_cylinder *cy, t_operation *op)
{
	t_ray	ray;
	t_vec3	hit_to_base;
	double	projection;

	ft_bzero(&ray, sizeof(t_ray));
	if (op->delta >= 0)
	{
		op->lambda = calculate_quadratic_root(*op);
		if (op->lambda > 0)
		{
			ray.hit_point = add_vec3(origin, scalar_mult(dir, op->lambda));
			hit_to_base = substract_vec3(ray.hit_point, cy->pos);
			projection = dot_product(&hit_to_base, &cy->normal);
			if (projection >= 0 && projection <= cy->height)
			{
				ray.hit = 1;
				ray.distance = op->lambda;
			}
		}
	}
	return (ray);
}

t_ray	hit_cylinder(t_vec3 dir, t_vec3 origin, t_cylinder *cy)
{
	t_ray			body_ray;
	t_ray			final_ray;
	t_operation		op;
	double			t_cap;
	t_vec3			cap_hit_point;

	get_abcd_cyl(cy, origin, dir, &op);
	body_ray = hit_cyl_body(dir, origin, cy, &op);
	final_ray = body_ray;
	op.tri.dir = dir;
	op.tri.origin = origin;
	if (check_cylinder_caps(op.tri, cy, &t_cap, &cap_hit_point))
	{
		if (!final_ray.hit || t_cap < final_ray.distance)
		{
			final_ray.hit = 2;
			final_ray.distance = t_cap;
			final_ray.hit_point = cap_hit_point;
		}
	}
	return (final_ray);
}
