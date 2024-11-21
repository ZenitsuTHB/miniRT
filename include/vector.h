/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:25:21 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/21 18:34:08 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include "struct.h"

// typedef struct  s_vector t_vec;
typedef struct s_vector	t_point;

/*
┏━━━━━━━━・▼・━━━━━━━━┓
	VECTOR FUNCTIONS
┗━━━━━━━━・▼・━━━━━━━━┛
*/
double					vector_length(t_vec3 v);
double					deg_to_rad(double degree);
double					euclidean_distance(t_vec3 v1, t_vec3 v2);

t_vec3					vproduct_vec3(t_vec3 *v1, t_vec3 *v2);

t_vec3					reflect_vec(t_vec3 light_dir, t_vec3 normal);
t_vec3					cross_product(const t_vec3 *v1, const t_vec3 *v2);
t_vec3					unit_vec3(t_vec3 v);
t_vec3					create_vec3(double x, double y, double z);
t_vec3					add_vec3(const t_vec3 vector1, const t_vec3 vector2);
t_vec3					substract_vec3(const t_vec3 vector1,
							const t_vec3 vector2);
t_vec3					multiply_vec3(t_vec3 vector1, t_vec3 vector2);
t_vec3					scalar_mult(t_vec3 vect, double factor);
t_vec3					scalar_div(t_vec3 vect, double factor);
double					dot_product(const t_vec3 *vector1,
							const t_vec3 *vector2);

#endif
