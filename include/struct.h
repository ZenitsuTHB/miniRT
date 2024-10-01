/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:22:11 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/01 13:19:45 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <math.h>
#include "vector.h"
#include "../libs/MLX42/include/MLX42/MLX42.h"

typedef struct s_mlx
{
	int         x;
	int         y;
	mlx_t       *con;
	mlx_image_t *img;
}             t_mlx;

typedef struct s_ambient
{
	double      ratio;
	t_rgb       color;
}             t_ambient;

typedef struct s_camera
{
	int			fov;
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
	t_vec3	pos;
	double 	bright;
	double ratio;       
	t_rgb color;        
	t_point light_point;
}				t_light;

typedef struct s_sphere
{
	t_rgb		color;
	t_vec3		pos;
	t_vec3		center;
	double 		radius;
	struct s_sphere		*next;
	struct s_sphere		*prev;
}				t_sphere;

typedef struct s_plane
{
	t_rgb		color;
	t_vec3 pos;
	t_vec3 normal;
	struct s_plane		*next;
	struct s_plane		*prev;
}				t_plane;

typedef struct s_cylinder
{
	t_vec3            pos;
	t_vec3            normal;
	double            radius;
	t_vec3            center;
	double            height;
	t_rgb             color;
	struct s_cylinder *next;
	struct s_cylinder *prev;
}	t_cylinder;

typedef struct s_cone
{
	t_vec3				pos;
	t_vec3				normal;
	double				radius;
	double				height;
	t_rgb				  color;
	struct s_cone *next;
	struct s_cone *prev;
}	t_cone;

typedef struct s_raytracing
{
	double		ratio;
	t_point		origin;
	t_vec3		direction;
	double    img_pl_width;
  double    img_pl_height;
}           t_ray;

 typedef struct s_objects
 {
   void             *object;
   struct s_objects *next;
}           t_objects;

typedef struct s_hit
{
	double t;     
	t_vec3 point;  
	t_vec3 normal; 
	t_objects *object;
}				t_hit;

typedef struct s_scene
{
	t_mlx       *mlx;
	t_ray       *ray;
  t_hit       *hit;
	t_plane     *planes;
	t_sphere    *spheres;
	t_camera    *camera;
	t_cone      *cones;
	t_light     *light;
	t_ambient   *ambient;
  t_cylinder  *cylinders;
}             t_scene;

// typedef union u_objects
// {
// 	t_cylinder			*cy;
// 	t_plane				*pl;
// 	t_sphere			*sp;
// 	t_cone				*cn;
// }						t_objects;

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
