/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:30:27 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/01 14:45:42 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_ambient	*set_ambient(char *str, int *error)
{
	t_ambient	*amb;
	char		**split;
	char		*err;

	amb = new_setup(1);
	if (!amb)
		return (NULL);
	split = ft_splitset(str, " \t");
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
	split = ft_splitset(str, " \t");
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

static t_light	*new_light(t_light *prev)
{
	t_light	*new;

	new = malloc(sizeof(t_light));
	if (!new)
		return (error_parser(YEL, MSG_MEM), NULL);
	new->next = NULL;
	if (prev)
	{
		prev->next = new;
		new->prev = prev;
	}
	else
		new->prev = NULL;
	return (new);
}

void	add_light(t_light **light, char *str, int *error)
{
	t_light	*obj;
	char	**split;
	char	*err;

	obj = new_light(*light);
	if (!obj)
		return ;
	split = ft_splitset(str, " \t");
	if (!split)
		return ;
	if (ft_splitlen(split) != 4)
		return (error_parser(YEL, MSG_NUM));
	if (set_pos(split[1], &obj->pos))
		return (free_split(split));
	obj->bright = ft_strtod(split[2], &err);
	if (*err || obj->bright < 0.0 || obj->bright > 1.0)
		return (free_split(split));
	if (set_color(split[3], &obj->color))
		return (free_split(split));
	free_split(split);
	*error = 0;
	*light = obj;
}
