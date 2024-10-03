/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:22:11 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/03 14:37:49 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <math.h>
#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

/*
┏━━━━━━━━・▼・━━━━━━━━┓
		INPUT
┗━━━━━━━━・▼・━━━━━━━━┛
*/

typedef struct s_vector
{
	double				x;
	double				y;
	double				z;
}	t_vec3;

typedef struct s_rgb
{
	int			red;
	int			green;
	int			blue;
	uint32_t	gradient;
}	t_rgb;

typedef struct s_mlx
{
	int         x;
	int         y;
	mlx_t       *con;
	mlx_image_t *img;
}             t_mlx;

typedef struct s_ambient
{
	double      bright;
	t_rgb       color;
}             t_ambient;

typedef struct s_camera
{
	t_vec3		pos;
	t_vec3		normal;
	int			fov;
	// Render
	double		focal_len;
	double		viewport_width;
	double		viewport_height;
	double		ratio;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_vec3		up;
	t_vec3		lower_left_corner;
	t_vec3		right;
	t_vec3		cam_dir;
}				t_camera;

typedef struct s_light
{
	t_vec3	pos;
	double 	bright;
	t_rgb 	color; 
}				t_light;

typedef struct s_sphere
{
	t_vec3		pos;
	double 		radius;
	t_rgb		color;
}				t_sphere;

typedef struct s_plane
{
	t_vec3 	pos;
	t_vec3 normal;
	t_rgb		color;
}				t_plane;

typedef struct s_cylinder
{
	t_vec3            pos;
	t_vec3            normal;
	double            radius;
	double            height;
	t_rgb             color;
}	t_cylinder;

typedef struct s_cone
{
	t_vec3				pos;
	t_vec3				normal;
	double				radius;
	double				height;
	t_rgb				color;
}	t_cone;

typedef struct s_shape
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
	t_cone		*co;
}	t_shape;

typedef struct s_obj
{
	int				id;
	t_shape			shape;
	struct s_obj	*next;
	struct s_obj	*prev;
}	t_obj;

typedef struct s_raytracing
{
	double		ratio;
	t_vec3		origin;
	t_vec3		direction;
	double    img_pl_width;
  	double    img_pl_height;
}           t_ray;

typedef struct s_hit
{
	double t;      // Distance from the ray's origin to the intersection point
	t_vec3 point;  // Intersection point
	t_vec3 normal; // Normal vector at the intersection point
	t_obj *object;//Pointer to the intersected object
}				t_hit;

typedef struct s_scene
{
	t_mlx		*mlx;
	// Parseo
	t_light		*light;
	t_camera	*camera;
	t_ambient	*ambient;
	t_obj		*obj;
	// Render
	t_ray		*ray;
	t_hit		*hit;
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

#endif // !_STRUCT_H
