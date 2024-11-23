/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_light_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:33:17 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/23 13:33:34 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

t_rgb	clamp_color(t_rgb color)
{
	color.x = fmin(255, fmax(0, color.x));
	color.y = fmin(255, fmax(0, color.y));
	color.z = fmin(255, fmax(0, color.z));
	return (color);
}

t_rgb	accumulation_color(t_rgb constant, t_rgb temp)
{
	t_rgb	saved;

	saved = add_vec3(constant, temp);
	return (saved);
}

uint32_t	gradient_color(t_rgb color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = (int)(color.x);
	g = (int)(color.y);
	b = (int)(color.z);
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	get_normal_and_color(t_vec3 hitpoint, t_obj **object)
{
	if ((*object)->id == SP)
	{
		(*object)->color = (*object)->shape.sp->color;
		(*object)->normal = unit_vec3(substract_vec3(hitpoint,
					(*object)->shape.sp->center));
	}
	else if ((*object)->id == PL)
	{
		(*object)->color = (*object)->shape.pl->color;
		(*object)->normal = (*object)->shape.pl->normal;
	}
	else if ((*object)->id == CY)
	{
		(*object)->color = (*object)->shape.cy->color;
		(*object)->normal = get_normal_cyl(hitpoint, (*object)->shape.cy);
	}
	else if ((*object)->id == CU)
	{
		(*object)->color = (*object)->shape.cu->color;
		(*object)->normal = get_normal_cube(hitpoint, (*object)->shape.cu);
	}
}

bool	is_shadowed(t_vec3 l_origin, t_vec3 l_dir, t_obj *obj, t_ray ray)
{
	t_ray	shadow;
	double	distance;

	ft_bzero(&shadow, sizeof(t_ray));
	distance = euclidean_distance(l_origin, ray.hit_point);
	while (obj)
	{
		if (obj == ray.object)
		{
			obj = obj->next;
			continue ;
		}
		hit_which_object(l_dir, l_origin, obj, &shadow);
		if (shadow.hit)
		{
			shadow.distance = euclidean_distance(l_origin, shadow.hit_point);
			if (shadow.distance <= distance)
				return (true);
		}
		obj = obj->next;
	}
	return (false);
}
