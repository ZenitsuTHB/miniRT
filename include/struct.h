/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:22:11 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/23 13:43:28 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <math.h>
# include <../libs/MLX42/include/MLX42/MLX42.h>

/*
┏━━━━━━━━・▼・━━━━━━━━┓
		INPUT
┗━━━━━━━━・▼・━━━━━━━━┛
*/

typedef struct s_vector
{
	double			x;
	double			y;
	double			z;
}	t_vec3;

typedef struct s_vector	t_rgb;

typedef struct s_mlx
{
	int				x;
	int				y;
	mlx_t			*con;
	mlx_image_t		*img;
}	t_mlx;

typedef struct s_ambient
{
	double			bright;
	t_rgb			color;
}	t_ambient;

typedef struct s_camera
{
	int				fov;
	t_vec3			origin;
	t_vec3			cam_dir;
	double			ratio;
	double			focal_len;
	double			vp_width;
	double			vp_height;
	t_vec3			up;
	t_vec3			right;
	t_vec3			neg_dir;
	t_vec3			vertical;
	t_vec3			horizontal;
	t_vec3			l_l_corner;
}	t_camera;

typedef struct s_light
{
	t_vec3			pos;
	t_rgb			color;
	double			bright;
	struct s_light	*next;
	struct s_light	*prev;
	t_vec3			direction;
}	t_light;

typedef struct s_sphere
{
	t_vec3			center;
	double			radius;
	t_rgb			color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3			pos;
	t_vec3			normal;
	t_rgb			color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3			pos;
	t_vec3			normal;
	double			radius;
	double			height;
	t_rgb			color;
}	t_cylinder;

typedef struct s_cube
{
	t_vec3			center;
	t_vec3			normal;
	double			size;
	t_rgb			color;
}	t_cube;

typedef union u_shape
{
	t_sphere		*sp;
	t_plane			*pl;
	t_cylinder		*cy;
	t_cube			*cu;
}	t_shape;

typedef struct s_obj
{
	int				id;
	t_shape			shape;
	struct s_obj	*next;
	struct s_obj	*prev;
	t_vec3			normal;
	t_rgb			color;
}	t_obj;

typedef struct s_ray
{
	int				hit;
	double			distance;
	t_vec3			origin;
	t_vec3			normal;
	t_vec3			hit_point;
	t_obj			*object;
	uint32_t		color;
}	t_ray;

typedef struct s_scene
{
	t_mlx			*mlx;
	t_light			*light;
	t_camera		*camera;
	t_ambient		*ambient;
	t_obj			*obj;
	t_ray			*ray;
}	t_scene;

typedef struct s_trilevec
{
	t_vec3			dir;
	t_vec3			origin;
	t_vec3			co;
}	t_triplevec;

typedef struct s_operation
{
	t_vec3			oc;
	double			a;
	double			b;
	double			c;
	double			t[2];
	double			delta;
	double			lambda;
	t_triplevec		tri;
}	t_operation;

typedef struct s_phong
{
	t_rgb			full;
	t_rgb			i_amb;
	t_rgb			diff;
	t_rgb			spec;
	t_rgb			finished;
}	t_phong;

#endif
