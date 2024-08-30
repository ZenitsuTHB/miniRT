/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:42:59 by avolcy            #+#    #+#             */
/*   Updated: 2024/08/27 19:44:56 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include "macros.h"
# include "struct.h"
# include <stdlib.h>
# include <unistd.h>
# include "../libs/libft/libft.h"
# include <../libs/MLX42/include/MLX42/MLX42.h>

# define WIDTH 1000
# define HEIGHT 1400

typedef struct s_win
{
	void	*mlx_img;
	void	*mlx_con;

}			t_win;
/*
┏━━━━━━━━・▼・━━━━━━━━┓
		INPUT
┗━━━━━━━━・▼・━━━━━━━━┛
*/

int			error_message(char *color, char *msg);
int			check_args(int argc, char *argv);

/*
┏━━━━━━━━・▼・━━━━━━━━┓
┗━━━━━━━━・▼・━━━━━━━━┛
*/

#endif
