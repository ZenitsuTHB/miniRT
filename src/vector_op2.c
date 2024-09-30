/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:16:34 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/23 12:18:32 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

// function to normalize a vector
t_vec3	unit_vec3(t_vec3 v)
{
	double	length;

	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (create_vec3(v.x / length, v.y / length, v.z / length));
}

double	deg_to_rad(double degree)
{
	return (degree * M_PI / 180.0);
}
