/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:15:59 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/23 12:19:59 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*
 *COLORS
 * */

# define NC "\001\033[0m\002"
# define RED "\001\033[0;31m\002"
# define CYAN "\001\033[0;36m\002"
# define BLE "\001\033[0;34m\002"
# define GRN "\001\033[0;32m\002"
# define WHT "\001\033[0;97m\002"
# define YEL "\001\033[0;33m\002"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define WIDTH 1000
# define HEIGHT 1000
# define IMG_W 1000 // WIDTH
# define IMG_H 1000 // HEIGHT
# define ERROR_ARG "Bad number of arguments detected !"
# define ERROR_EXTENSION "Bad file extension !"
# define ERROR_WIND "Can't initialize Window !"

#endif
