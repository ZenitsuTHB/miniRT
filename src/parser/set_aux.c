/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:16:52 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/23 17:34:40 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parser.h"
#include "../../libs/libft/libft.h"

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
	rgb->red = ft_atoi_error(split[0], &error);
	if (error || rgb->red < 0 || rgb->red > 255)
		return (free_split(split), error_parser(YEL, MSG_DATA), 1);
	rgb->green = ft_atoi_error(split[1], &error);
	if (error || rgb->green < 0 || rgb->green > 255)
		return (free_split(split), error_parser(YEL, MSG_DATA), 1);
	rgb->blue = ft_atoi_error(split[2], &error);
	if (error || rgb->blue < 0 || rgb->blue > 255)
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
	return (0);
}
