/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:40:34 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/23 12:44:25 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	error_parser(char *color, char *msg)
{
	printf(RED "\n\tError\n");
	printf("\t%s%s\n\n" NC, color, msg);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_splitlen(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	get_angle(double height, double radius, double *angle)
{
	const double	min = 0.0;
	const double	max = M_PI / 2;

	if (!height)
		return (0);
	*angle = atan(radius / height);
	if (*angle > min && *angle < max)
		return (0);
	return (error_parser(YEL, "The angle is wrong (angle(0-90)"
			"= atan(radius / height))"), 1);
}
