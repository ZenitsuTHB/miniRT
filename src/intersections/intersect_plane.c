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

bool hit_plane(t_ray *ray, t_plane *plane, double *t)
{
    double denom;
    
    denom = dot_product(&plane->normal, &ray->direction);
    if (fabs(denom) > 1e-6)// If denom is not close to 0 (ray not parallel to plane)
    { 
        t_vec3 p0l0 = substract_vec3(plane->normal, ray->origin);
        *t = dot_product(&p0l0, &plane->normal) / denom;
        if (*t >= 0)
            return(true);// Intersection is in front of the ray's origin
    }
    return (false);  // Ray is parallel to the plane
}
