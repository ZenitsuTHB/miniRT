/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:42:59 by avolcy            #+#    #+#             */
/*   Updated: 2024/08/26 16:55:43 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include "macros.h"
# include "vector.h"
# include <stdlib.h>
# include <unistd.h>
# include "../libs/libft/libft.h"
# include <../libs/MLX42/include/MLX42/MLX42.h>

# define WIDTH 1000
# define HEIGHT 1400

typedef struct s_win
{
	void	*mlx_window;
	void	*mlx_connection;

}			t_win;

int			check_args(int argc, char *argv);

#endif
