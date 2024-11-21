/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:00:11 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/21 17:14:23 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include "../libs/libft/libft.h"

t_vec3	create_vec3(double x, double y, double z)
{
	t_vec3	new_vec;

	ft_bzero(&new_vec, sizeof(t_vec3));
	new_vec.x = x;
	new_vec.y = y;
	new_vec.z = z;
	return (new_vec);
}

t_vec3	add_vec3(const t_vec3 v1, const t_vec3 v2)
{
	return (create_vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vec3	substract_vec3(const t_vec3 v1, const t_vec3 v2)
{
	return (create_vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vec3	multiply_vec3(t_vec3 v1, t_vec3 v2)
{
	return (create_vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z));
}
