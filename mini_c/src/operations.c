/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:00:11 by avolcy            #+#    #+#             */
/*   Updated: 2024/08/13 19:32:49 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector* add_vec(t_vector* result, const t_vector* v)
{
	result->x += v->x;
	result->y += v->y;
	result->z += v->z;

	return  (result);
}
