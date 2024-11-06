/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:16:34 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/06 01:46:25 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double vector_length(t_vec3 v)
{
	double length;
	
	length = (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
	length = sqrt(length);
	return (length);
}

/* function to normalize a vector*/
t_vec3	unit_vec3(t_vec3 v)
{
	double	length;

	length = vector_length(v);	
	if (length == 0)
		return ((t_vec3){0, 0, 0});
	return (create_vec3(v.x / length, v.y / length, v.z / length));
}

double	deg_to_rad(double degree)
{
	return (degree * M_PI / 180.0);
}

//EUCLI_DIST = sqrt(pow((x2-x1),2) + pow((y2-y1)2) + pow((z2-z1),2))
double	euclidean_distance(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;
	double	distance;
	
	res = substract_vec3(v2, v1);
	distance = (res.x * res.x) + (res.y * res.y) + (res.z * res.z);
	return (sqrt(distance));
}
