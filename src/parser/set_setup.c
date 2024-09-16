/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:30:27 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/16 18:53:50 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft/libft.h"
#include "../../headers/parser.h"
#include "../../headers/macros.h"

int	set_ambient(t_ambient *amb, char *str)
{
	char		**split;
	char		*error;

	amb = new_ambient();
	if (!amb)
		return (1);
	split = ft_split(str, ' ');
	if (!split)
		return (error_parser(YEL, MSG_MEM), 1);
	if (ft_splitlen(split) != 3)
		return (error_parser(YEL, MSG_NUM), 1);
	amb->ratio = ft_strtod(split[1], &error);
	if (*error || amb->ratio < 0.0 || amb->ratio > 1.0)
		return (error_parser(YEL, MSG_DATA), 1);
	//if (set_color(split[2], &amb->color))//
	//	return (free_split(split), 1);
	free_split(split);
	return (0);
}

int	set_camera(t_camera *cam, char *str)
{
	char	**split;

	// Nuevo
	split = ft_split(str, ' ');
	if (!split)
		return (1);
	// Pos
	// Normal (-1, 1)
	// Fov (0, 180)


	cam++;
	free_split(split);
	return (0);

}

int	set_light(t_light *light, char *str)
{
	char	**split;

	// Nuevo
	split = ft_split(str, ' ');
	if (!split)
		return (1);
	// Pos
	// Bright (0, 1)
	// Color (0, 255)

	light++;
	free_split(split);
	return (0);

}
