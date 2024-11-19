/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:13:17 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/16 20:13:51 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vec3	scalar_substract(t_vec3 v, double scalar)
{
	return (create_vec3(v.x - scalar, v.y - scalar, v.z - scalar));
}

// a vector multiplied by a scalar
t_vec3	scalar_mult(t_vec3 v, double scalar)
{
	return (create_vec3(v.x * scalar, v.y * scalar, v.z * scalar));
}

// a vector divided by a scalar
t_vec3	scalar_div(t_vec3 v, double scalar)
{
	if (scalar == 0)
		return ((t_vec3){0, 0, 0});
	return (create_vec3(v.x / scalar, v.y / scalar, v.z / scalar));
}

// or scalar product
double	dot_product(const t_vec3 *v1, const t_vec3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec3	cross_product(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3	res;

	res.x = v1->y * v2->z - v1->z * v2->y;
	res.y = v1->z * v2->x - v1->x * v2->z;
	res.z = v1->x * v2->y - v1->y * v2->x;
	return (res);
}
