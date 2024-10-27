/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:51:00 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/27 12:16:24 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_ray	hit_cone(t_vec3 dir, t_vec3 origin, t_cone *co)
{
	t_ray		ray;
	t_operation	op;
	t_vec3		axis;
	t_vec3		hitcone;
	double		tan;
	double		dot_axis[2];
	double		sqrt_delta;
	double		t;
	double		height;

	printf("Pintar CO\n");
	ray.hit = false;

	op.OC = substract_vec3(origin, co->pos);
	axis = unit_vec3(co->normal);

	tan = (co->radius / co->height) * (co->radius / co->height);
	
	dot_axis[0] = dot_product(&dir, &axis);
	dot_axis[1] = dot_product(&op.OC, &axis);

	op.A = dot_product(&dir, &dir) - (1 + tan) * dot_axis[0] * dot_axis[0];
	op.B = 2 * dot_product(&dir, &op.OC) - (1 + tan) * dot_axis[0] * dot_axis[1];
	op.C = dot_product(&op.OC, &op.OC) - (1 + tan) * dot_axis[1] * dot_axis[1];

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
	hitcone = substract_vec3(ray.hit_point, co->pos);
	height = dot_product(&hitcone, &axis);

	if (height < 0 || height > co->height)
		return (ray);

	printf("Pintado CO\n");
	ray.hit = true;
	ray.distance = t;
	ray.normal = unit_vec3(substract_vec3(hitcone, scalar_mult(axis, height * (1 + tan))));

	return (ray);
}
