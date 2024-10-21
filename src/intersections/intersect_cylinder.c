/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:54:54 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/21 12:46:07 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

double  calculate_quadratic_root2(t_operation op)
{
  double  sqrted_delta;
  
  if (op.delta == 0)
    return (-op.B) / (2.0 * op.A);
  sqrted_delta = sqrt(op.delta);
  op.t[0] = (-op.B - sqrted_delta) / (2.0 * op.A);
  op.t[1] = (-op.B + sqrted_delta) / (2.0 * op.A);
  if (op.t[0] >= 0 && op.t[0] < op.t[1])
    return (op.t[0]);
  else if (op.t[1] >= 0)
    return (op.t[1]);
  return (-1.0);
}

t_ray	hit_cylinder(t_vec3 dir, t_vec3	origin, t_cylinder *cy)
{
	t_ray		ray;
	t_operation	op;

	ray.hit = false;
	op.OC = substract_vec3(cy->pos, origin);
	op.A = dot_product(&dir, &dir);
	op.B = 2.0 * dot_product(&op.OC, &dir);
	op.C = dot_product(&op.OC, &op.OC) - (cy->radius * cy->radius);
	op.delta = (op.B * op.B) - (4.0 * op.A * op.C);
	if (op.delta <= 0)
		return (ray);
	ray.distance = calculate_quadratic_root2(op);
	if (ray.distance < 0)
		return (ray);
	ray.hit = true;
	ray.hit_point = add_vec3(origin, scalar_mult(dir, ray.distance));
	ray.normal = unit_vec3(substract_vec3(dir, cy->pos));
	return (ray);
}
/*
t_ray	hit_cylinder(t_vec3 dir, t_vec3	origin, t_cylinder *cy)
{
	t_ray		ray;
	t_vec3		oc_proj;
	t_vec3		dir_proj;
	t_vec3		hit_point;
	t_vec3		tmp;
	double		height_check;
	t_operation	op;

	ray.hit = false;
	op.OC = substract_vec3(origin, cy->pos);
	dir_proj = substract_vec3(dir, scalar_mult(cy->normal, dot_product(&dir, &cy->normal)));
	oc_proj = substract_vec3(op.OC, scalar_mult(cy->normal, dot_product(&op.OC, &cy->normal)));
	op.A = dot_product(&dir_proj, &dir_proj);
	op.B = 2.0 * dot_product(&dir_proj, &oc_proj);
	op.C = dot_product(&oc_proj, &oc_proj) - (cy->radius * cy->radius);
	op.delta = (op.B * op.B) - (4.0 * op.A * op.C);
	if (op.delta < 0)
		return (ray);
	op.t[0] = (-op.B - sqrt(op.delta)) / (2.0 * op.A);
	op.t[1] = (-op.B + sqrt(op.delta)) / (2.0 * op.A);
	if (op.t[0] >= 0)
		ray.distance = op.t[0];
	else if (op.t[1] >= 0)
		ray.distance = op.t[1];
	else
		return (ray);
	hit_point = add_vec3(origin, scalar_mult(dir, ray.distance));
	tmp = substract_vec3(hit_point, cy->pos);
	height_check = dot_product(&cy->normal, &tmp);
	if (height_check < 0 || height_check > cy->height)
		return (ray);
	ray.hit = true;
	tmp = substract_vec3(hit_point, cy->pos);
	ray.normal = substract_vec3(tmp, scalar_mult(cy->normal, dot_product(&tmp, &cy->normal)));
	ray.normal = norm_vec3(ray.normal);
	return (ray);
}*/
