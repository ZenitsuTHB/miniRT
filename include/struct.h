/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:28:57 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/15 19:26:22 by avolcy           ###   ########.fr       */
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

typedef struct s_mlx
{
	int         x;
	int         y;
	mlx_t       *con;
	mlx_image_t *img;
}             t_mlx;

typedef struct s_ambient
{
	double    ratio;//[0.0 , 1.0] : 0.2
	t_rgb     color;// [0-255]: 255, 255, 255
}           t_ambient;

//A vector is normalize when its magnitude(length) = 1;
//Normalization is done by dividing each vect component by the vect magnitude
//magnitude = V (x, y, z) -> |v| = (x^2 + y^2 + z^2)^2
/*
 * CAMERA INFOS
 * view_point -50.0, 0.0, 20.0
 * orientation [-1, 1] 0.0, 0.0, 1.0
 * field_of_view horizontal view [0, 180]: 70 
 * closer to 0° = zoom in, closer to 180° = zoom out a FOV 70 
 * extend 35° to left and 35° to right
 */

typedef struct s_camera
{
	double    fov;
	double    focal_len;
	double    viewport_width;
	double    viewport_height;
  double    ratio;
	t_vec3    horizontal;
	t_vec3    vertical;
	t_vec3    up;
  t_vec3    lower_left_corner;
	t_vec3    right;
	t_vec3    pos;
	t_vec3    normal;
  t_vec3    cam_dir;
}           t_camera;

typedef struct  s_light
{
	double    ratio;//[0.0, 1.0]: 0.6
	t_rgb     color;//[0-255]: 10, 0, 255
	t_point   light_point;//-4.0, 50.0, 0.0
}           t_light;

typedef struct s_sphere
{
	t_rgb     color;
	double    diameter;//12.6
	t_vec3    center;// 0.0, 0.0, 20.6
}           t_sphere;

typedef struct s_plane
{
	t_rgb     color;
	t_vec3    origin;//(0.0, 0.0, -10.0)
	t_vec3    normal;//[-1, 1]( 0.0, 1.0, 0.0)
}           t_plane;

typedef struct s_cylinder
{
	t_rgb     color;
	double    height;//21.42
	double    diameter;//14.2
	double    normal;// 0.0, 0.0, 1.0
	t_vec3    center;//50.0, 0.0, 20.6
}           t_cylinder;

typedef struct s_cone
{
	t_vec3    pos;
	t_vec3    normal;
	double    diameter;
	double    height;
	t_rgb     color;
}           t_cone;

typedef struct s_raytracing
{
  double    ratio;
	t_point   origin;
  t_vec3    direction;
}           t_ray;

typedef struct s_scene
{
  t_ray     *ray;
	t_mlx     *mlx;
	t_plane   *planes;
	t_camera  *camera;
	//t_cone		*cones;
	//t_light   *light;
	//t_sphere    *spheres;
	//t_ambient   *ambient;
	//t_cylinder	*cylinders;
}           t_scene;

// typedef struct s_world
// {
//     t_objects       type;
// 	  t_materia       materia;
//     bool            (*hit)(const t_ray *, t_objects, t_hit *);
//     void            (*free_type)(t_objects);
//     t_rgb           (*get_color)(t_vec3 *, struct s_world *, t_img_tex *);
//     struct s_world  *next;
// }                   t_world;
//BONUS DATA

#endif // !_STRUCT_H
