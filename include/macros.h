/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:15:59 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/30 22:23:10 by marvin           ###   ########.fr       */
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

# define SP 1
# define PL 2

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
# define MALLOC_ERROR "Allocation Failed !!!"
# define RENDER_ERROR "Failed to Render_Image"
# define MSG_FEW "Too few arguments!"
# define MSG_TOO "Too many arguments!"
# define MSG_EXT "Bad file extension!"
# define MSG_OPEN "The file does not exists!"
# define MSG_MEM "Fail to allocate memory!"
# define MSG_OBJ "Wrong object: "
# define MSG_AMB "You need an ambient light!"
# define MSG_CAM "You need a camera!"
# define MSG_LIGHT "You need a light!"
# define MSG_TAMB "You have more than one ambient light!"
# define MSG_TCAM "You have more than one camera!"
# define MSG_TLIGHT "You have more than one light!"
# define MSG_NUM "Wrong number of elements in an object!"
# define MSG_DATA "Wrong data in the element!"

#endif
