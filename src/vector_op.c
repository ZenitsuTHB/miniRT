/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:00:11 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/02 16:55:12 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void init_vector(t_vector *vector)
{
	ft_bzero(vector, sizeof(t_vector));
}

t_vector	adding_vect(const t_vector* vect1, const t_vector* vect2)
{
	t_vector result;

	result.x = vect1->x + vect2->x;
	result.y = vect1->y + vect2->y; 
	result.z = vect1->z + vect2->z;

	return  (result);
}

t_vector	substracting_vect(const t_vector* vect1, const t_vector* vect2)
{
	t_vector result;

	result.x = vect1->x - vect2->x;
	result.y = vect1->y - vect2->y; 
	result.z = vect1->z - vect2->z;

	return  (result);
}

t_vector vect_prod_vect(t_vector *vect1, t_vector *vect2)
{
	t_vector res;

	res.x = vect1->x * vect2->x;
	res.y = vect1->y * vect2->y;
	res.z = vect1->z * vect2->z;

	return (res);
}



void	product_vect(t_vector* vect, double factor)
{
	vect.x *= factor;
	vect.y *= factor; 
	vect.z *= factor;
}

void	division_vect(t_vector* vect, double factor)
{
	vect.x /= factor;
	vect.y /= factor; 
	vect.z /= factor;

	return  (result);
}

double	dot_product(const t_vector* vect1, const t_vector* vect2)
{
	return (vect1->x * vect2->x + vec1->y * vect2->y, + vect1->z * vect2->z);
}

// function to normalize a vector
t_vec3 unit_vector(t_vec3 v)
{
    double length bd;
    
    length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return vec3(v.x / length, v.y / length, v.z / length);
}
