/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:54:54 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/27 12:16:36 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_ray	hit_cylinder(t_vec3 dir, t_vec3 origin, t_cylinder *cy)
{
	t_ray		ray;
	t_operation	op;
	t_vec3		cy_axis;
	t_vec3		tmp;
	double		sqrt_delta;
	double		height;
	double t;	

	printf("Pintar CY\n");
	ray.hit = false;

	op.OC = substract_vec3(cy->pos, origin);
	cy_axis = unit_vec3(cy->normal);

	op.A = dot_product(&dir, &dir) - pow(dot_product(&dir, &cy_axis), 2);
	op.B = 2 * (dot_product(&dir, &op.OC) - dot_product(&dir, &cy_axis) * dot_product(&op.OC, &cy_axis));
	op.C = dot_product(&op.OC, &op.OC) - pow(dot_product(&op.OC, &cy_axis), 2) - pow(cy->radius, 2);

	op.delta = op.B * op.B - 4 * op.A * op.C;
	if (op.delta < 0)
		return (ray);

	sqrt_delta = sqrt(op.delta);
	op.t[0] = (-op.B - sqrt_delta) / (2 * op.A);
	op.t[1] = (-op.B + sqrt_delta) / (2 * op.A);

	t = (op.t[0] > 0) ? op.t[0] : ((op.t[1] > 0) ? op.t[1] : -1);
	if (t < 0)
		return (ray);

	ray.hit_point = add_vec3(origin, scalar_mult(dir, t));
	tmp = substract_vec3(ray.hit_point, cy->pos);
	height = dot_product(&tmp, &cy_axis);

	if (height < 0 || height > cy->height)
		return (ray);

	printf("Pintado CY\n");
	ray.hit = true;
	ray.distance = t;
	ray.normal = unit_vec3(substract_vec3(tmp, scalar_mult(cy_axis, height)));
	return (ray);
}
