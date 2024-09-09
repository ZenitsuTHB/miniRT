/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:25:21 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/04 22:07:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;

} t_vec3;

//typedef struct  s_vector t_vec;
typedef struct  s_vector t_point;
typedef struct  s_vector t_rgb;

/*
┏━━━━━━━━・▼・━━━━━━━━┓
	VECTOR FUNCTIONS
┗━━━━━━━━・▼・━━━━━━━━┛
*/

t_vec3	unit_vec3(t_vec3 v);
t_vec3	create_vect(double x, double y, double z);
t_vec3	adding_vect(const t_vec3 vector1, const t_vec3 vector2);
t_vec3	substracting_vect(const t_vec3 vector1, const t_vec3 vector2);
t_vec3	vect_prod_vect(t_vec3 vector1, t_vec3 vector2);
t_vec3	scalar_mult(t_vec3 vect, double factor);
t_vec3	scalar_div(t_vec3 vect, double factor);
double	dot_product(const t_vec3* vector1, const t_vec3* vector2);




#endif
