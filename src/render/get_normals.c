/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:08:06 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/23 13:59:15 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

// Función para calcular la normal de un cubo en el punto de impacto
t_vec3 get_normal_cube(t_vec3 hit_point, t_cube *cu) {
    t_vec3 normal;

    // Distancia del punto de impacto con respecto al centro del cubo
    t_vec3 delta = substract_vec3(hit_point, cu->center);

    if (fabs(delta.x) > fabs(delta.y) && fabs(delta.x) > fabs(delta.z))
        normal = (delta.x > 0) ? (t_vec3){1, 0, 0} : (t_vec3){-1, 0, 0};
    else if (fabs(delta.y) > fabs(delta.x) && fabs(delta.y) > fabs(delta.z))
        normal = (delta.y > 0) ? (t_vec3){0, 1, 0} : (t_vec3){0, -1, 0};
    else
        normal = (delta.z > 0) ? (t_vec3){0, 0, 1} : (t_vec3){0, 0, -1};
    return normal;
}


t_vec3	get_normal_cyl(t_vec3 hp, t_cylinder *cy)
{
	t_vec3	cy_to_hit;
	t_vec3	proj;
	t_vec3	normal;

	cy_to_hit = substract_vec3(hp, cy->pos);
	proj = scalar_mult(cy->normal, dot_product(&cy_to_hit, &cy->normal));
	normal = substract_vec3(cy_to_hit, proj);
	return (unit_vec3(normal));
}
