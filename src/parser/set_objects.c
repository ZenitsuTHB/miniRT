/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:34:09 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/21 14:36:03 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parser.h"
#include "../../libs/libft/libft.h"

void add_sphere(t_sphere **sphere, char *str, int *error)
{
	t_sphere	*sp;
	char		**split;
	char		*err;

	*error = 1;
	sp = new_sphere(*sphere);
	if (!sp)
		return ;
	split = ft_split(str, ' ');
	if (!split)
		return ;
	if (set_pos(split[1], &sp->pos))
		return (free_split(split));
	sp->diameter = ft_strtod(split[2], &err);
	if (*err)
		return (free_split(split));
	if (set_color(split[3], &sp->color))
		return (free_split(split));
	*error = 0;
	*sphere = sp;
}

void add_plane(t_plane **plane, char *str, int *error)
{

	plane++;
	str++;
	*error = 0;
}

void add_cylinder(t_cylinder **cyl, char *str, int *error)
{
	
	cyl++;
	str++;
	*error = 0;
}

void add_cone(t_cone **cone, char *str, int *error)
{

	cone++;
	str++;
	*error = 0;
}
