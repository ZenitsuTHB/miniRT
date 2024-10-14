/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:42:59 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/14 23:01:37 by marvin           ###   ########.fr       */
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

int			init_window(t_mlx *mlx);
uint32_t	gradient_color(t_rgb color);

// RENDER
int			render_object(t_scene *scene);
int			setting_up_camera(t_camera *camera);
void		generate_ray(t_camera *camera, t_ray *ray, int i, int j);
t_ray       hit_sphere(t_vec3 direction, t_vec3 , t_sphere *);
bool        hit_plane(t_ray *ray, t_plane *plane, double *t);
t_vec3      get_pixel_direction(t_camera *cam, int pixel_x, int pixel_y);



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
