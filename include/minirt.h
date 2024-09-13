/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:42:59 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/13 20:45:30 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include "vector.h"
# include "macros.h"
# include "struct.h"
# include <stdlib.h>
# include <unistd.h>
# include "../libs/libft/libft.h"
# include <../libs/MLX42/include/MLX42/MLX42.h>

/*
┏━━━━━━━━・▼・━━━━━━━━┓
		INPUT
┗━━━━━━━━・▼・━━━━━━━━┛
*/

uint32_t	gradient_color(t_rgb color);
int			init_window(t_mlx *mlx);

int			render_object(t_scene *scene);

int			error_message(char *color, char *msg);
int			check_args(int argc, char *argv);

void manage_escape(mlx_key_data_t keydata, void *param);
/*
┏━━━━━━━━・▼・━━━━━━━━┓
┗━━━━━━━━・▼・━━━━━━━━┛
*/

#endif
