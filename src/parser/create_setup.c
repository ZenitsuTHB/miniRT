/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:05:09 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/30 13:23:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"
#include <stdlib.h>

void	*new_setup(int type)
{
	void	*new;

	new = NULL;
	if (type == 1)
		new = malloc(sizeof(t_ambient));
	else if (type == 2)
		new = malloc(sizeof(t_camera));
	else if (type == 3)
		new = malloc(sizeof(t_light));
	if (!new)
		return (error_parser(YEL, MSG_MEM), NULL);
	return (new);
}

t_sphere	*new_sphere(t_sphere *prev)
{
	t_sphere	*new;

	new = malloc(sizeof(t_sphere));
	if (!new)
		return (error_parser(YEL, MSG_MEM), NULL);
	new->next = NULL;
	if (prev)
	{
		while (prev->next)
			prev = prev->next;
		new->prev = prev;
		prev->next = new;
	}
	else
		new->prev = NULL;
	return (new);
}

t_plane	*new_plane(t_plane *prev)
{
	t_plane	*new;

	new = malloc(sizeof(t_plane));
	if (!new)
		return (error_parser(YEL, MSG_MEM), NULL);
	new->next = NULL;
	if (prev)
		new->prev = prev;
	else
		new->prev = NULL;
	return (new);
}

t_cylinder	*new_cylinder(t_cylinder *prev)
{
	t_cylinder	*new;

	new = malloc(sizeof(t_cylinder));
	if (!new)
		return (error_parser(YEL, MSG_MEM), NULL);
	new->next = NULL;
	if (prev)
		new->prev = prev;
	else
		new->prev = NULL;
	return (new);
}

t_cone	*new_cone(t_cone *prev)
{
	t_cone	*new;

	new = malloc(sizeof(t_cone));
	if (!new)
		return (error_parser(YEL, MSG_MEM), NULL);
	new->next = NULL;
	if (prev)
		new->prev = prev;
	else
		new->prev = NULL;
	return (new);
}
