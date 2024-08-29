/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:42:59 by avolcy            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/08/28 14:28:21 by adrmarqu         ###   ########.fr       */
=======
/*   Updated: 2024/08/27 19:44:56 by avolcy           ###   ########.fr       */
>>>>>>> input
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

<<<<<<< HEAD
typedef struct s_win
{
	void	*mlx_img;
	void	*mlx_con;

}			t_win;
=======
/*
┏━━━━━━━━・▼・━━━━━━━━┓
		INPUT
┗━━━━━━━━・▼・━━━━━━━━┛
*/
>>>>>>> input

int			error_message(char *color, char *msg);
int			check_args(int argc, char *argv);

/*
┏━━━━━━━━・▼・━━━━━━━━┓
┗━━━━━━━━・▼・━━━━━━━━┛
*/

#endif
