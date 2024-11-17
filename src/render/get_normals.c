/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:08:06 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/17 17:34:50 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/*
t_vec3	get_normal_cyl(t_vec3 hp, t_cylinder *cy)
{
	t_vec3	ap;
	t_vec3	normal;
	double	m;

	ap = substract_vec3(hp, cy->pos);
	m = dot_product(&ap, &cy->normal);
	ap = add_vec3(cy->pos, scalar_mult(cy->normal, m));
	normal = substract_vec3(hp, ap);
	return (unit_vec3(normal));
}*/

t_vec3	get_normal_cone(t_vec3 hp, t_cone *co)
{
	t_vec3	normal;
	t_vec3	ap;
	double	m;
	double	k;

	k = co->radius / co->height;
	ap = substract_vec3(hp, co->pos);
	m = dot_product(&ap, &co->normal);
	ap = add_vec3(co->pos, scalar_mult(co->normal, m));
	normal = substract_vec3(hp, ap);
	ap = scalar_mult(co->normal, k * sqrt(dot_product(&normal, &normal)));
	normal = substract_vec3(normal, ap);
	return (unit_vec3(normal));
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
