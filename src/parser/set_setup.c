/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:30:27 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/23 18:08:52 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft/libft.h"
#include "../../headers/parser.h"
#include "../../headers/macros.h"

t_ambient	*set_ambient(char *str, int *error)
{
	t_ambient	*amb;
	char		**split;
	char		*err;

	amb = new_setup(1);
	if (!amb)
		return (NULL);
	split = ft_split(str, ' ');
	if (!split)
		return (error_parser(YEL, MSG_MEM), NULL);
	if (ft_splitlen(split) != 3)
		return (error_parser(YEL, MSG_NUM), NULL);
	amb->ratio = ft_strtod(split[1], &err);
	if (*err || amb->ratio < 0.0 || amb->ratio > 1.0)
		return (error_parser(YEL, MSG_DATA), NULL);
	if (set_color(split[2], &amb->color))
		return (free_split(split), NULL);
	*error = 0;
	free_split(split);
	return (amb);
}

t_camera	*set_camera(char *str, int *error)
{
	t_camera	*cam;
	char		**split;
	int			err;

	cam = new_setup(2);
	if (!cam)
		return (NULL);
	split = ft_split(str, ' ');
	if (!split)
		return (error_parser(YEL, MSG_MEM), NULL);
	if (ft_splitlen(split) != 4)
		return (error_parser(YEL, MSG_NUM), NULL);
	if (set_pos(split[1], &cam->pos))
		return (free_split(split), NULL);
	if (set_normal(split[2], &cam->normal))
		return (free_split(split), NULL);
	err = 0;
	cam->fov = ft_atoi_error(split[3], &err);
	if (err || cam->fov < 0 || cam->fov > 180)
		return (free_split(split), NULL);
	*error = 0;
	free_split(split);
	return (cam);
}

t_light	*set_light(char *str, int *error)
{
	t_light	*light;
	char	**split;
	char	*err;

	light = new_setup(3);
	if (!light)
		return (NULL);
	split = ft_split(str, ' ');
	if (!split)
		return (NULL);
	if (ft_splitlen(split) != 4)
		return (error_parser(YEL, MSG_NUM), NULL);
	if (set_pos(split[1], &light->pos))
		return (free_split(split), NULL);
	light->bright = ft_strtod(split[2], &err);
	if (*err || light->bright < 0.0 || light->bright > 1.0)
		return (free_split(split), NULL);
	if (set_color(split[3], &light->color))
		return (free_split(split), NULL);
	free_split(split);
	*error = 0;
	return (light);
}
