/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:10:35 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/21 13:32:03 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	delete_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (!len || (len == 1 && line[0] == '\n'))
		return (0);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (1);
}
static int	init_scene_null(t_scene *scene)
{
	scene->light = NULL;
	scene->camera = NULL;
	scene->ambient = NULL;
	scene->obj = NULL;
	return (0);
}

static int	read_data(int fd, t_scene *scene)
{
	t_obj 	*obj;
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*line != '#')
		{
			if (delete_newline(line))
				if (set_data(scene, line))
					return (free(line), 1);
		}
		free(line);
	}
	obj = scene->obj;
	while (obj->prev)
		obj = obj->prev;
	scene->obj = obj;
	if (!scene->ambient)
		return (error_parser(YEL, MSG_AMB), 1);
	if (!scene->camera)
		return (error_parser(YEL, MSG_CAM), 1);
	if (!scene->light)
		return (error_parser(YEL, MSG_LIGHT), 1);
	return (0);
}

static int	ft_open_file(char *name)
{
	int	fd;
	int	len;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (error_parser(YEL, MSG_OPEN), fd);
	len = ft_strlen(name) - 3;
	if (len <= 3 || ft_strncmp(name + len, ".rt", 3))
		return (error_parser(YEL, MSG_EXT), -1);
	return (fd);
}

int	read_file(int ac, char *file, t_scene *scene)
{
	int		fd;

	init_scene_null(scene);
	if (ac < 2)
		return (error_parser(YEL, MSG_FEW), 1);
	else if (ac > 2)
		return (error_parser(YEL, MSG_TOO), 1);
	fd = ft_open_file(file);
	if (fd == -1)
		return (1);
	if (read_data(fd, scene))
		return (close(fd), 1);
	close(fd);
	return (0);
}
