/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:42:59 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/02 16:32:00 by avolcy           ###   ########.fr       */
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

int			error_message(char *color, char *msg);
int			check_args(int argc, char *argv);

/*
┏━━━━━━━━・▼・━━━━━━━━┓
┗━━━━━━━━・▼・━━━━━━━━┛
*/

#endif
