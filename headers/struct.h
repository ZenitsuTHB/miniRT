/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:28:57 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/30 18:20:29 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRUCT_H
# define _STRUCT_H

# include <math.h>

typedef struct s_rgb
{
	int					red;
	int					green;
	int					blue;
	unsigned int		hex_color;
}	t_rgb;

typedef struct s_vector
{
	double				x;
	double				y;
	double				z;
}	t_vec3;

typedef struct s_ambient
{
	double				ratio;
	t_rgb				color;
}	t_ambient;

typedef struct s_camera
{
	t_vec3				pos;
	t_vec3				normal;
	int					fov; 
}	t_camera;

typedef struct s_light
{
	t_vec3				pos;
	double				bright;
	t_rgb				color;
}	t_light;

typedef struct s_sphere
{
	t_vec3				pos;
	double				radious;
	t_rgb				color;
	struct s_sphere		*next;
	struct s_sphere		*prev;
}	t_sphere;

typedef struct s_plane
{
	t_vec3				pos;
	t_vec3				normal;
	t_rgb				color;
	struct s_plane		*next;
	struct s_plane		*prev;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3				pos;
	t_vec3				normal;
	double				radious;
	double				height;
	t_rgb				color;
	struct s_cylinder	*next;
	struct s_cylinder	*prev;
}	t_cylinder;

typedef struct s_cone
{
	t_vec3				pos;
	t_vec3				normal;
	double				radious;
	double				height;
	t_rgb				color;
	struct s_cone		*next;
	struct s_cone		*prev;
}	t_cone;

typedef struct s_scene
{
	void				*img;
	t_ambient			*ambient;
	t_camera			*camera;
	t_light				*light;
	t_sphere			*spheres;
	t_plane				*planes;
	t_cylinder			*cylinders;
	t_cone				*cones;
}	t_scene;

#endif
