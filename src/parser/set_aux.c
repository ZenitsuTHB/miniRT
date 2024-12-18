/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:16:52 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/23 16:57:36 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	set_color(char *str, t_rgb *rgb)
{
	char	**split;
	int		error;

	split = ft_split(str, ',');
	if (!split)
		return (error_parser(YEL, MSG_MEM), 1);
	if (ft_splitlen(split) != 3)
		return (free_split(split), error_parser(YEL, MSG_NUM), 1);
	error = 0;
	rgb->x = ft_atoi_error(split[0], &error);
	if (error || rgb->x < 0 || rgb->x > 255)
		return (free_split(split), error_parser(YEL, MSG_DATA), 1);
	rgb->y = ft_atoi_error(split[1], &error);
	if (error || rgb->y < 0 || rgb->y > 255)
		return (free_split(split), error_parser(YEL, MSG_DATA), 1);
	rgb->z = ft_atoi_error(split[2], &error);
	if (error || rgb->z < 0 || rgb->z > 255)
		return (free_split(split), error_parser(YEL, MSG_DATA), 1);
	free_split(split);
	return (0);
}

int	set_pos(char *str, t_vec3 *pos)
{
	char	**split;
	char	*error;

	split = ft_split(str, ',');
	if (!split)
		return (error_parser(YEL, MSG_MEM), 1);
	if (ft_splitlen(split) != 3)
		return (free_split(split), error_parser(YEL, MSG_NUM), 1);
	pos->x = ft_strtod(split[0], &error);
	if (*error)
		return (free_split(split), error_parser(YEL, MSG_DATA), 1);
	pos->y = ft_strtod(split[1], &error);
	if (*error)
		return (free_split(split), error_parser(YEL, MSG_DATA), 1);
	pos->z = ft_strtod(split[2], &error);
	if (*error)
		return (free_split(split), error_parser(YEL, MSG_DATA), 1);
	free_split(split);
	return (0);
}

int	set_normal(char *str, t_vec3 *normal)
{
	char	**split;
	char	*error;

	split = ft_split(str, ',');
	if (!split)
		return (error_parser(YEL, MSG_MEM), 1);
	if (ft_splitlen(split) != 3)
		return (free_split(split), error_parser(YEL, MSG_NUM), 1);
	normal->x = ft_strtod(split[0], &error);
	if (*error || normal->x < -1.0 || normal->x > 1.0)
		return (free_split(split), error_parser(YEL, MSG_DATA), 1);
	normal->y = ft_strtod(split[1], &error);
	if (*error || normal->y < -1.0 || normal->y > 1.0)
		return (free_split(split), error_parser(YEL, MSG_DATA), 1);
	normal->z = ft_strtod(split[2], &error);
	if (*error || normal->z < -1.0 || normal->z > 1.0)
		return (free_split(split), error_parser(YEL, MSG_DATA), 1);
	free_split(split);
	if (!normal->x && !normal->y && !normal->z)
		return (error_parser(YEL, "Normal can not be 0,0,0"), 1);
	*normal = unit_vec3(*normal);
	return (0);
}
