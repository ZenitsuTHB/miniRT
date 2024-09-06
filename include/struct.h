/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:28:57 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/04 22:06:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRUCT_H
# define _STRUCT_H

# include <math.h>
#include "minirt.h"
# include <../libs/MLX42/include/MLX42/MLX42.h>


/*
┏━━━━━━━━・▼・━━━━━━━━┓
		INPUT
┗━━━━━━━━・▼・━━━━━━━━┛
*/

typedef struct s_img
{
	mlx_image_t	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	int		x;
	int		y;
	void	*con;
	t_img	*img;
} t_mlx;

//TODO if ft_strcmp()
typedef enum s_object
{
	A,
	C,
	L,
	sp,
	pl,
	cy
}	t_obj;

typedef struct s_ambient
{
	double	ratio; //[0.0 , 1.0] : 0.2
	int		rgb_color; // [0-255]: 255, 255, 255
}			t_amb;

//A vector is normalize when its magnitude(length) = 1;
//Normalization is done by dividing each vect component by the vect magnitude
//magnitude = V (x, y, z) -> |v| = (x^2 + y^2 + z^2)^2
typedef struct s_cam
{
	
	t_vec3	*view_point;//-50.0,0,20
	t_vec3	*orientation;//[-1, 1] 0.0, 0.0, 1.0
	double	field_of_view;//horizontal view [0, 180]: 70, 
	//closer to 0° = zoom in, closer to 180° = zoom out a FOV 70 
	//extend 35° to left and 35° to right
}			t_cam;

typedef struct  s_light
{
	t_vec3	*light_point;//-4.0, 50.0, 0.0
	double	ratio;//[0.0, 1.0]: 0.6
	t_rgb		color;//[0-255]: 10, 0, 255
}			t_lite;

typedef struct s_sphere
{
	t_vec3	*center;// 0.0, 0.0, 20.6
	double	diameter;//12.6
	t_rgb		color;
	
}			t_sphere;

typedef struct s_plane
{
	t_vec3		*point;//0.0, 0.0, -10.0
	double		normal;//[-1, 1] 0.0, 1.0, 0.0
	t_rgb		color;
}			t_plane;

typedef struct s_cylinder
{
	t_vec3		*center;//50.0, 0.0, 20.6
	double		normal;// 0.0, 0.0, 1.0
	double		diameter;//14.2
	double		height;//21.42
	t_rgb		color;
}				t_cyli;

typedef struct s_raytracing 
{
	t_obj		object;
	t_vec3		origin;
    t_vec3		direction;
}				t_ray;

//BONUS DATA


#endif // !_STRUCT_H
