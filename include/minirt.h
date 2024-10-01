/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:42:59 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/01 13:07:05 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/libft.h"
# include "struct.h"
# include "vector.h"
# include "macros.h"
# include "parser.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
bool		hit_sphere(t_ray *ray, t_sphere *sp, double *t);

int			error_message(char *color, char *msg);
int			read_file(int ac, char *file, t_scene *scene);
void		draw_scene(t_scene *scene);

void		manage_escape(mlx_key_data_t keydata, void *param);
void		free_scene(t_scene *scene);

void		print_scene(t_scene scene);

/*
┏━━━━━━━━・▼・━━━━━━━━┓
    PARSER
┗━━━━━━━━・▼・━━━━━━━━┛
*/


#endif
