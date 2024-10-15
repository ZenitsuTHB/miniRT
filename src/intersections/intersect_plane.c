/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:07:31 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/30 22:07:31 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

t_ray   hit_plane(t_vec3 direction, t_vec3 origin, t_plane *pl)
{
    t_ray   ray;
    double  denom;
    
    ray.hit = false;
    denom = dot_product(&pl->normal, &direction);
    if (fabs(denom) > 1e-6)// If denom is not close to 0 (ray not parallel to plane)
    { 
        t_vec3 p0l0 = substract_vec3(pl->normal, origin);
        ray.distance = dot_product(&p0l0, &pl->normal) / denom;
        if (ray.distance >= 0)
        {
            ray.hit = true;
            return (ray);// Intersection is in front of the ray's origin
        }
    }
    return (ray);  // Ray is parallel to the plane
}
