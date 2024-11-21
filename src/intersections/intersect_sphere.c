/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/21 18:46:57 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

double	calculate_quadratic_root(t_operation op)
{
	double	sqrted_delta;

	if (op.delta == 0)
		return (-op.b / 2.0 * op.a);
	sqrted_delta = sqrt(op.delta);
	op.t[0] = (-op.b - sqrted_delta) / (2.0 * op.a);
	op.t[1] = (-op.b + sqrted_delta) / (2.0 * op.a);
	if (op.t[0] >= 0 && op.t[0] < op.t[1])
		return (op.t[0]);
	else if (op.t[1] >= 0)
		return (op.t[1]);
	return (-1.0);
}

// ray.hit_point = O + t.D,
t_ray	hit_sphere(t_vec3 direction, t_vec3 origin, t_sphere *sp)
{
	t_ray		ray;
	t_operation	op;

	ft_bzero(&ray, sizeof(t_ray));
	ft_bzero(&op, sizeof(t_operation));
	ray.hit = false;
	op.oc = substract_vec3(origin, sp->center);
	op.a = dot_product(&direction, &direction);
	op.b = 2.0 * dot_product(&op.oc, &direction);
	op.c = dot_product(&op.oc, &op.oc) - (sp->radius * sp->radius);
	op.delta = op.b * op.b - (4 * op.a * op.c);
	if (op.delta < 0)
		return (ray);
	op.lambda = calculate_quadratic_root(op);
	if (op.lambda < 0)
		return (ray);
	ray.hit = true;
	ray.hit_point = add_vec3(origin, scalar_mult(direction, op.lambda));
	return (ray);
}
