/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:42:59 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/14 22:31:14 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/libft.h"
# include "macros.h"
# include "struct.h"
# include "vector.h"
# include "parser.h"
# include <../libs/MLX42/include/MLX42/MLX42.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	init_mlx(t_scene *scene);

/*
┏━━━━━━━━・▼・━━━━━━━━┓
		INPUT
┗━━━━━━━━・▼・━━━━━━━━┛
*/

//debug
void print_vec3(t_vec3 v);

uint32_t phong_shading(t_ray *ray, t_light *light, t_camera *cam);
t_rgb	accumulation_color(t_rgb constant, t_rgb temp);
t_rgb	clamp_color(t_rgb color);
void	get_normal_and_color(t_vec3 hitpoint, t_obj **object);
uint32_t	gradient_color(t_rgb color);

bool	is_shadowed(t_vec3 l_origin, t_vec3 l_dir, t_obj *obj, t_ray ray);

int			init_window(t_mlx *mlx);
uint32_t	gradient_color(t_rgb color);

// RENDER
int			render_object(t_scene *scene);
double	calculate_quadratic_root(t_operation op);
int			setting_up_camera(t_camera *camera);
void		generate_ray(t_camera *camera, t_ray *ray, int i, int j);
t_ray       hit_sphere(t_vec3 direction, t_vec3 , t_sphere *);
t_ray       hit_plane(t_vec3 direction, t_vec3 origin, t_plane *pl);
t_ray       hit_cylinder(t_vec3 dir, t_vec3 origin, t_cylinder *cy);
t_ray       hit_cone(t_vec3 dir, t_vec3 origin, t_cone *co);
t_vec3      get_pixel_direction(t_camera *cam, int pixel_x, int pixel_y);
uint32_t    get_phong_effect(t_ray ray, t_scene *scene, t_obj *obj);
void		calculate_t(t_operation *op);
void	hit_which_object(t_vec3 direction, t_vec3 origin, t_obj *obj, t_ray *ray);
t_vec3		get_normal_cyl(t_vec3 hp, t_cylinder *cy);
t_vec3		get_normal_cone(t_vec3 hp, t_cone *co);



int			error_message(char *color, char *msg);
int			read_file(int ac, char *file, t_scene *scene);
void		draw_scene(t_scene *scene);

void		manage_escape(mlx_key_data_t keydata, void *param);

/*
┏━━━━━━━━・▼・━━━━━━━━┓
        PARSER
┗━━━━━━━━・▼・━━━━━━━━┛
*/

void   free_scene(t_scene *scene);
int read_file(int ac, char *file, t_scene *scene);

void	print_scene(t_scene scene);

#endif
