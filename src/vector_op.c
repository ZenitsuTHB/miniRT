/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:00:11 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/06 19:35:45 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "../libs/libft/libft.h"

t_vec3	create_vec3(double x, double y, double z)
{
	t_vec3 new_vec;
	
	ft_bzero(&new_vec, sizeof(t_vec3));
	new_vec.x = x;
	new_vec.y = y;
	new_vec.z = z;
	return (new_vec);
}

void init_vec3(t_vec3 *vector)
{
	ft_bzero(vector, sizeof(t_vec3));
}

t_vec3	add_vec3(const t_vec3 v1, const t_vec3 v2)
{
	return  create_vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

t_vec3	substract_vec3(const t_vec3 v1, const t_vec3 v2)
{
	return  create_vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

t_vec3 multiply_vec3(t_vec3 v1, t_vec3 v2)
{
	return create_vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

// a vector multiplied by a scalar
t_vec3	scalar_mult(t_vec3 v, double scalar)
{
	return create_vec3(v.x * scalar, v.y * scalar, v.z * scalar);
}

// a vector divided by a scalar
t_vec3	scalar_div(t_vec3 v, double scalar)
{
	return create_vec3(v.x / scalar, v.y / scalar, v.z / scalar);
}

//or scalar product
double	dot_product(const t_vec3* v1, const t_vec3* v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec3  cross_product(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3  res;

	res.x = v1->y * v2->z - v1->z * v2->y;
	res.y = v1->z * v2->x - v1->x * v2->z;
	res.z = v1->x * v2->y - v1->y * v2->x;
	return (res);
}

// function to normalize a vector
t_vec3 unit_vec3(t_vec3 v)
{
    double length;
    
    length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return create_vec3(v.x / length, v.y / length, v.z / length);
}

double  deg_to_rad(double degree)
{
	return (degree * M_PI / 180.0);
}
