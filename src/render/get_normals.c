/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:08:06 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/23 14:26:35 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static t_vec3	get_normal_cube2(double delta, int x, int y, int z)
{
	t_vec3	normal;

	if (delta > 0)
		normal = (t_vec3){x, y, z};
	else
		normal = (t_vec3){-x, -y, -z};
	return (normal);
}

t_vec3	get_normal_cube(t_vec3 hit_point, t_cube *cu)
{
	t_vec3	normal;
	t_vec3	delta;

	delta = substract_vec3(hit_point, cu->center);
	if (fabs(delta.x) > fabs(delta.y) && fabs(delta.x) > fabs(delta.z))
		normal = get_normal_cube2(delta.x, 1, 0, 0);
	else if (fabs(delta.y) > fabs(delta.x) && fabs(delta.y) > fabs(delta.z))
		normal = get_normal_cube2(delta.y, 0, 1, 0);
	else
		normal = get_normal_cube2(delta.z, 0, 0, 1);
	return (normal);
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
