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

t_vec3	create_vect(double x, double y, double z)
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

t_vec3	adding_vect(const t_vec3 v1, const t_vec3 v2)
{
	return  create_vect(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

t_vec3	substracting_vect(const t_vec3 v1, const t_vec3 v2)
{
	return  create_vect(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

t_vec3 vect_prod_vect(t_vec3 v1, t_vec3 v2)
{
	return create_vect(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

// a vector multiplied by a scalar
t_vec3	scalar_mult(t_vec3 v, double scalar)
{
	return create_vect(v.x * scalar, v.y * scalar, v.z * scalar);
}

// a vector divided by a scalar
t_vec3	scalar_div(t_vec3 v, double scalar)
{
	return create_vect(v.x / scalar, v.y / scalar, v.z / scalar);
}

double	dot_product(const t_vec3* v1, const t_vec3* v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

// function to normalize a vector
t_vec3 unit_vec3(t_vec3 v)
{
    double length;
    
    length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return create_vect(v.x / length, v.y / length, v.z / length);
}
