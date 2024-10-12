/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:30:27 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/12 23:19:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	set_ambient(t_scene *scene, char *data, int *error)
{
	t_ambient	*amb;
	char		**split;
	char		*err;

	amb = malloc(sizeof(t_ambient));
	if (!amb)
		return (error_parser(YEL, MSG_MEM));
	split = ft_splitset(data, " \t");
	if (!split)
		return (error_parser(YEL, MSG_MEM));
	if (ft_splitlen(split) != 3)
		return (free_split(split), error_parser(YEL, MSG_NUM));
	amb->bright = ft_strtod(split[1], &err);
	if (*err || amb->bright < 0.0 || amb->bright > 1.0)
		return (free_split(split), error_parser(YEL, MSG_DATA));
	if (set_color(split[2], &(amb->color)))
		return (free_split(split));
	free_split(split);
	scene->ambient = amb;
	*error = 0;
}

static void	init_other_variable(t_camera **cam)
{
	(*cam)->focal_len = 1.0;
	(*cam)->ratio = (double)WIDTH / (double)HEIGHT;
	(*cam)->vp_width = 0.0;
	(*cam)->vp_height = 0.0;
	(*cam)->up = (t_vec3){0.0, 0.0, 0.0};
	(*cam)->right = (t_vec3){0.0, 0.0, 0.0};
	(*cam)->neg_dir = (t_vec3){0.0, 0.0, 0.0};
	(*cam)->vertical = (t_vec3){0.0, 0.0, 0.0};
	(*cam)->horizontal = (t_vec3){0.0, 0.0, 0.0};
	(*cam)->l_l_corner = (t_vec3){0.0, 0.0, 0.0};
}
void	set_camera(t_scene *scene, char *data, int *error)
{
	t_camera	*cam;
	char		**split;
	int			err;
	
	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (error_parser(YEL, MSG_MEM));
	split = ft_splitset(data, " \t");
	if (!split)
		return (error_parser(YEL, MSG_MEM));
	if (ft_splitlen(split) != 4)
		return (free_split(split), error_parser(YEL, MSG_NUM));
	if (set_pos(split[1], &cam->origin))
		return (free_split(split));
	if (set_normal(split[2], &cam->cam_dir))
		return (free_split(split));
	err = 0;
	cam->fov = ft_atoi_error(split[3], &err);
	if (err || cam->fov < 0 || cam->fov > 180)
		return (free_split(split), error_parser(YEL, MSG_DATA));
	free_split(split);
	init_other_variable(&cam);
	scene->camera = cam;
	*error = 0;
}

void	set_light(t_scene *scene, char *data, int *error)
{
	t_light	*light;
	char	**split;
	char	*err;

	light = malloc(sizeof(t_light));
	if (!light)
		return (error_parser(YEL, MSG_MEM));
	split = ft_splitset(data, " \t");
	if (!split)
		return (error_parser(YEL, MSG_MEM));
	if (ft_splitlen(split) != 4)
		return (free_split(split), error_parser(YEL, MSG_NUM));
	if (set_pos(split[1], &(light->pos)))
		return (free_split(split));
	light->bright = ft_strtod(split[2], &err);
	if (*err || light->bright < 0.0 || light->bright > 1.0)
		return (free_split(split), error_parser(YEL, MSG_DATA));
	if (set_color(split[3], &(light->color)))
		return (free_split(split));
	free_split(split);
	scene->light = light;
	*error = 0;
}
