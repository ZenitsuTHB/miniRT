/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:00:11 by avolcy            #+#    #+#             */
/*   Updated: 2024/08/13 20:13:20 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void init_structs(t_vector *vector)
{
	vector->x = 0;
	vector->y = 0;
	vector->z = 0;
}

t_vector* add_vec(t_vector* result, const t_vector* v)
{
	result->x += v->x;
	result->y += v->y;
	result->z += v->z;

	return  (result);
}

t_vector* mult_vec(t_vector* result, const t_vector* v)
{
	result->x *= v->x;
	result->y *= v->y;
	result->z *= v->z;

	return  (result);
}

double vector_get(t_vector* v, int i)
{
	return ();
}

double vector_set(){}
