/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:54:54 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/24 12:57:54 by adrmarqu         ###   ########.fr       */
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
