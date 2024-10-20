/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:54:54 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/20 18:22:36 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_ray	hit_cylinder(t_vec3 direction, t_vec3 origin, t_cylinder *cy)
{
	t_ray	ray;
	t_vec3	oc_proj;
	t_vec3	dir_proj;
	t_vec3	hit_point;
	t_vec3	tmp;
	double	height_check;
	t_operation	op;

	ray.hit = false;
	
	op.OC = substract_vec3(origin, cy->pos);
	dir_proj = substract_vec3(direction, scalar_mult(cy->normal, dot_product(&direction, &cy->normal)));
	oc_proj = substract_vec3(op.OC, scalar_mult(cy->normal, dot_product(&op.OC, &cy->normal)));
	
	op.A = dot_product(&dir_proj, &dir_proj);
	op.B = 2.0 * dot_product(&dir_proj, &oc_proj);
	op.C = dot_product(&oc_proj, &oc_proj) - (cy->radius * cy->radius);

	op.delta = (op.B * op.B) - (4 * op.A * op.C);
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

	hit_point = add_vec3(origin, scalar_mult(direction, ray.distance));
	tmp = substract_vec3(hit_point, cy->pos);
	height_check = dot_product(&cy->normal, &tmp);
	if (height_check < 0 || height_check > cy->height)
		return (ray);

	ray.hit = true;
	ray.normal = cy->normal;
	//ray.normal = normalize_vec3(substract_vec3(hit_point, cy->pos));

	return (ray);
}
