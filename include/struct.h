/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:22:11 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/04 22:10:24 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "minirt.h"
#include "vector.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>
#include <math.h>

/*
┏━━━━━━━━・▼・━━━━━━━━┓
		INPUT
┗━━━━━━━━・▼・━━━━━━━━┛
*/

typedef struct s_mlx
{
	int			x;
	int			y;
	mlx_t		*con;
	mlx_image_t	*img;
}				t_mlx;

typedef struct s_ambient
{
	double ratio;
	t_rgb color;
}				t_ambient;

typedef struct s_camera
{
	double		fov;
	double		focal_len;
	double		viewport_width;
	double		viewport_height;
	double		ratio;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_vec3		up;
	t_vec3		lower_left_corner;
	t_vec3		right;
	t_vec3		pos;
	t_vec3		normal;
	t_vec3		cam_dir;
}				t_camera;

typedef struct s_light
{
	double ratio;
	t_rgb color;
	t_point light_point;
}				t_light;

typedef struct s_sphere
{
	t_rgb		color;
	t_vec3 center;
	double radius;
}				t_sphere;

typedef struct s_plane
{
	t_rgb		color;
	t_vec3 origin;
	t_vec3 normal;
}				t_plane;

typedef struct s_cylinder
{
	t_rgb		color;
	double height;
	double normal;
	t_vec3 center;
	double diameter;
}				t_cylinder;

typedef struct s_cone
{
	t_vec3		pos;
	t_rgb		color;
	t_vec3		normal;
	double		height;
	double		diameter;
}				t_cone;

typedef struct s_raytracing
{
	double		ratio;
	t_point		origin;
	t_vec3		direction;
	double    img_pl_width;
  	double    img_pl_height;
}           t_ray;
typedef union u_shape
{
	t_cylinder			*cy;
	t_plane				*pl;
	t_sphere			*sp;
	t_cone				*cn;
}						t_shape;

typedef struct s_objects
{
	int					type;
	t_shape				*shape;
	struct s_objects	*next;
}           t_objects;

typedef struct s_hit
{
	double t;      // Distance from the ray's origin to the intersection point
	t_vec3 point;  // Intersection point
	t_vec3 normal; // Normal vector at the intersection point
	t_objects *object;//Pointer to the intersected object
}				t_hit;

typedef struct s_scene
{
	t_mlx		*mlx;
	t_ray		*ray;
	t_hit		*hit;//has a t_objects to carry the objects
	t_plane		*planes;
	t_sphere	*spheres;
	t_camera	*camera;
	// t_light   *light;
	// t_ambient   *ambient;
	// t_cylinder	*cylinders;
}				t_scene;


// typedef struct s_world
// {
//     t_objects       type;
// 		t_materia       materia;
//     bool            (*hit)(const t_ray *, t_objects, t_hit *);
//     void            (*free_type)(t_objects);
//     t_rgb           (*get_color)(t_vec3 *, struct s_world *, t_img_tex *);
//     struct s_world  *next;
// }                   t_world;
// BONUS DATA

#endif
