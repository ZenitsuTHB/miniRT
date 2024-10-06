/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:25:21 by avolcy            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/04 22:39:41 by avolcy           ###   ########.fr       */
=======
/*   Updated: 2024/10/05 12:04:14 by adrmarqu         ###   ########.fr       */
>>>>>>> parser
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include "struct.h"
<<<<<<< HEAD
=======

// typedef struct  s_vector t_vec;
typedef struct s_vector	t_point;
>>>>>>> parser

/*
┏━━━━━━━━・▼・━━━━━━━━┓
	VECTOR FUNCTIONS
┗━━━━━━━━・▼・━━━━━━━━┛
*/

double					deg_to_rad(double degree);
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
