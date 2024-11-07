/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:05:28 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/07 01:09:03 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

t_ray	hit_plane(t_vec3 direction, t_vec3 origin, t_plane *pl)
{
	t_ray	ray;
	t_vec3	p0l0;
	double	denom;
	double	lambda;
	double	quotient;

	ft_bzero(&ray, sizeof(t_ray));
	ray.hit = false;
	denom = dot_product(&pl->normal, &direction);
	if (fabs(denom) > 1e-6)
	{
		p0l0 = substract_vec3(pl->pos, origin);
		quotient = dot_product(&p0l0, &pl->normal);
		lambda = quotient / denom;
		if (lambda >= 0)
		{
			ray.hit = true;
			ray.hit_point = add_vec3(origin, scalar_mult(direction, lambda));
			return (ray);
		}
	}
	return (ray);
}
