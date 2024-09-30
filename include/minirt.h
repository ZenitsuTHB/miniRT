/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:42:59 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/30 22:50:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/libft.h"
# include "macros.h"
# include "struct.h"
# include "vector.h"
# include <../libs/MLX42/include/MLX42/MLX42.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	init_scene(t_scene *scene);

/*
┏━━━━━━━━・▼・━━━━━━━━┓
		INPUT
┗━━━━━━━━・▼・━━━━━━━━┛
*/

int			init_window(t_mlx *mlx);
uint32_t	gradient_color(t_rgb color);

// RENDER
int			render_object(t_scene *scene);
int			setting_camera(t_camera *camera);
void		generate_ray(t_camera *camera, t_ray *ray, int i, int j);
bool	hit_sphere(t_ray *ray, t_sphere *sp, double *t);
bool hit_plane(t_ray *ray, t_plane *plane, double *t);


int			error_message(char *color, char *msg);
int			check_args(int argc, char *argv);

void		manage_escape(mlx_key_data_t keydata, void *param);
/*
┏━━━━━━━━・▼・━━━━━━━━┓
┗━━━━━━━━・▼・━━━━━━━━┛
*/

#endif
