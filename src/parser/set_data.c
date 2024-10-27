/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:59:55 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/27 11:17:33 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static char	*get_id(char *str)
{
	char	**split;
	char	*id;

	split = ft_split(str, ' ');
	if (!split)
		return (NULL);
	id = ft_strdup(split[0]);
	free_split(split);
	return (id);
}

static int	dup_control(char *id)
{
	static int	ambient = 0;
	//static int	light = 0;
	static int	camera = 0;

	if (!ft_strncmp(id, "A", 1))
		ambient++;
	//if (!ft_strncmp(id, "L", 1))
	//	light++;
	if (!ft_strncmp(id, "C", 1))
		camera++;
	if (ambient > 1)
		return (error_parser(YEL, MSG_TAMB), 1);
	//if (light > 1)
	//	return (error_parser(YEL, MSG_TLIGHT), 1);
	if (camera > 1)
		return (error_parser(YEL, MSG_TCAM), 1);
	return(0);
}

int	set_data(t_scene *scene, char *str)
{
	char		*id;
	int			error;

	error = 1;
	id = get_id(str);
	if (!id)
		return (error_parser(YEL, MSG_MEM), 1);
	if (dup_control(id))
		return (free(id), 1);
	if (!ft_strncmp(id, "A", 2))
		set_ambient(scene, str, &error);
	else if (!ft_strncmp(id, "C", 2))
		set_camera(scene, str, &error);
	else if (!ft_strncmp(id, "L", 2))
		set_light(scene, str, &error);
	else
		set_object(scene, id, str, &error);
	free(id);
	return (error);
}
