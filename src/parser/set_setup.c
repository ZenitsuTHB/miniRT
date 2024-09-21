/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:30:27 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/21 13:17:20 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft/libft.h"
#include "../../headers/parser.h"
#include "../../headers/macros.h"

static void	set_error(int *error)
{
	*error = 1;
}

t_ambient	*set_ambient(char *str, int *error)
{
	t_ambient	*amb;
	char		**split;
	char		*err;

	amb = new_setup(1);
	if (!amb)
		return (set_error(error), NULL);
	split = ft_split(str, ' ');
	if (!split)
		return (error_parser(YEL, MSG_MEM), set_error(error), NULL);
	if (ft_splitlen(split) != 3)
		return (error_parser(YEL, MSG_NUM), set_error(error), NULL);
	amb->ratio = ft_strtod(split[1], &err);
	if (*err || amb->ratio < 0.0 || amb->ratio > 1.0)
		return (error_parser(YEL, MSG_DATA), set_error(error), NULL);
	if (set_color(split[2], &amb->color))
		return (free_split(split), set_error(error), NULL);
	free_split(split);
	return (amb);
}

t_camera	*set_camera(char *str, int *error)
{
	t_camera	*cam;
	char		**split;
	char		*err;

	cam = new_setup(2);
	if (!cam)
		return (set_error(error), NULL);
	split = ft_split(str, ' ');
	if (!split)
		return (error_parser(YEL, MSG_MEM), set_error(error), NULL);
	if (ft_splitlen(split) != 4)
		return (error_parser(YEL, MSG_NUM), set_error(error), NULL);
	if (set_pos(split[1], &cam->pos))
		return (free_split(split), set_error(error), NULL);
	if (set_normal(split[2], &cam->normal))
		return (free_split(split), set_error(error), NULL);
	cam->fov = ft_strtod(split[3], &err);
	if (*err || cam->fov < 0 || cam->fov > 180)
		return (free_split(split), set_error(error), NULL);
	free_split(split);
	return (cam);
}

t_light		*set_light(char *str, int *error)
{
	t_light	*light;
	char	**split;
	char	*err;

	light = new_setup(3);
	if (!light)
		return (set_error(error), NULL);
	split = ft_split(str, ' ');
	if (!split)
		return (set_error(error), NULL);
	if (ft_splitlen(split) != 4)
		return (error_parser(YEL, MSG_NUM), set_error(error), NULL);
	if (set_pos(split[1], &light->pos))
		return (free_split(split), set_error(error), NULL);
	light->bright = ft_strtod(split[2], &err);
	if (*err || light->bright < 0.0 || light->bright > 1.0)
		return (free_split(split), set_error(error), NULL);
	if (set_color(split[3], &light->color))
		return (free_split(split), set_error(error), NULL);
	free_split(split);
	return (light);
}
