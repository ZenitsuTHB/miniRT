/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:59:55 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/01 13:50:10 by adrmarqu         ###   ########.fr       */
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

static int	put_data_scene(char *id, char *data, t_scene *scene)
{
	int	error;

	error = 1;
	if (!ft_strncmp(id, "A", 1))
		scene->ambient = set_ambient(data, &error);
	else if (!ft_strncmp(id, "C", 1))
		scene->camera = set_camera(data, &error);
	else if (!ft_strncmp(id, "L", 1))
		add_light(&(scene->light), data, &error);
	else if (!ft_strncmp(id, "sp", 2))
		add_sphere(&(scene->spheres), data, &error);
	else if (!ft_strncmp(id, "pl", 2))
		add_plane(&(scene->planes), data, &error);
	else if (!ft_strncmp(id, "cy", 2))
		add_cylinder(&(scene->cylinders), data, &error);
	else if (!ft_strncmp(id, "co", 2))
		add_cone(&(scene->cones), data, &error);
	else
		return (printf(RED "\n\tError\n" YEL "\t%s%s\n\n" NC, MSG_OBJ, id), 1);
	return (error);
}

static int	dup_control(char *id)
{
	static int	ambient = 0;
	static int	camera = 0;

	if (!ft_strncmp(id, "A", 1))
		ambient++;
	if (!ft_strncmp(id, "C", 1))
		camera++;
	if (ambient > 1)
		return (error_parser(YEL, MSG_TAMB), 1);
	if (camera > 1)
		return (error_parser(YEL, MSG_TCAM), 1);
	return (0);
}

int	set_data(t_scene *scene, char *str)
{
	char		*id;

	id = get_id(str);
	if (!id)
		return (error_parser(YEL, MSG_MEM), 1);
	if (dup_control(id))
		return (free(id), 1);
	if (put_data_scene(id, str, scene))
		return (free(id), 1);
	free(id);
	return (0);
}
