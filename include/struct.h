/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:28:57 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/04 15:19:00 by marvin           ###   ########.fr       */
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


typedef struct s_ambient
{
	
	char	A;
	double	ratio; //[0.0 , 1.0] : 0.2
	int		rgb_color; // [0-255]: 255, 255, 255
}			t_amb;

//A vector is normalize when its magnitude(length) = 1;
//Normalization is done by dividing each vect component by the vect magnitude
//magnitude = V (x, y, z) -> |v| = (x^2 + y^2 + z^2)^2
typedef struct s_cam
{
	
	char	C;
	t_vec	*view_point;//-50.0,0,20
	t_vec	*orientation;//[-1, 1] 0.0, 0.0, 1.0
	double	field_of_view;//horizontal view [0, 180]: 70, 
	//closer to 0° = zoom in, closer to 180° = zoom out a FOV 70 
	//extend 35° to left and 35° to right
}			t_cam;

typedef struct  s_light
{
	
	char	L;
	t_vec	*light_point;//-4.0, 50.0, 0.0
	double	ratio;//[0.0, 1.0]: 0.6
	int		rgb_color;//[0-255]: 10, 0, 255
}			t_lite;

typedef struct s_sphere
{

	char	sp;
	t_vec	*center;// 0.0, 0.0, 20.6
	double	diameter;//12.6
	int		rgb_color;
	
}			t_sphere;

typedef struct s_plane
{

	char	pl;
	t_vec	*point;//0.0, 0.0, -10.0
	double	normal;//[-1, 1] 0.0, 1.0, 0.0
	int		rgb_color;
}			t_plane;

typedef struct s_cylinder
{
	char	cy;
	t_vec	*center;//50.0, 0.0, 20.6
	double	normal;// 0.0, 0.0, 1.0
	double	diameter;//14.2
	double	height;//21.42
	int		rgb_color;
}			t_cyli;

typedef struct s_raytracing 
{
	t_mlx		mlx;
	t_amb		ambient;
	t_cam		camera;
	t_lite		light;
	t_sphere	sphere;
	t_plane		plane;
	t_cyli		cylinder;
	
}			t_ray;

//BONUS DATA


#endif // !_STRUCT_H
