/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:34:09 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/30 18:20:26 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parser.h"
#include "../../libs/libft/libft.h"

void	add_sphere(t_sphere **sphere, char *str, int *error)
{
	t_sphere	*obj;
	char		**split;
	char		*err;

	obj = new_sphere(*sphere);
	if (!obj)
		return ;
	split = ft_split(str, ' ');
	if (!split)
		return ;
	if (set_pos(split[1], &obj->pos))
		return (free_split(split));
	obj->radious = ft_strtod(split[2], &err) / 2;
	if (*err)
		return (free_split(split));
	if (set_color(split[3], &obj->color))
		return (free_split(split));
	free_split(split);
	*error = 0;
	*sphere = obj;
}

void	add_plane(t_plane **plane, char *str, int *error)
{
	t_plane		*obj;
	char		**split;

	obj = new_plane(*plane);
	if (!obj)
		return ;
	split = ft_split(str, ' ');
	if (!split)
		return ;
	if (set_pos(split[1], &obj->pos))
		return (free_split(split));
	if (set_normal(split[2], &obj->normal))
		return (free_split(split));
	if (set_color(split[3], &obj->color))
		return (free_split(split));
	free_split(split);
	*error = 0;
	*plane = obj;
}

void	add_cylinder(t_cylinder **cyl, char *str, int *error)
{
	t_cylinder	*obj;
	char		**split;
	char		*err;

	obj = new_cylinder(*cyl);
	if (!obj)
		return ;
	split = ft_split(str, ' ');
	if (!split)
		return ;
	if (set_pos(split[1], &obj->pos))
		return (free_split(split));
	if (set_normal(split[2], &obj->normal))
		return (free_split(split));
	obj->radious = ft_strtod(split[3], &err) / 2;
	if (*err)
		return (free_split(split));
	obj->height = ft_strtod(split[4], &err);
	if (*err)
		return (free_split(split));
	if (set_color(split[5], &obj->color))
		return (free_split(split));
	free_split(split);
	*error = 0;
	*cyl = obj;
}

void	add_cone(t_cone **cone, char *str, int *error)
{
	t_cone		*obj;
	char		**split;
	char		*err;

	obj = new_cone(*cone);
	if (!obj)
		return ;
	split = ft_split(str, ' ');
	if (!split)
		return ;
	if (set_pos(split[1], &obj->pos))
		return (free_split(split));
	if (set_normal(split[2], &obj->normal))
		return (free_split(split));
	obj->radious = ft_strtod(split[3], &err) / 2;
	if (*err)
		return (free_split(split));
	obj->height = ft_strtod(split[4], &err);
	if (*err)
		return (free_split(split));
	if (set_color(split[5], &obj->color))
		return (free_split(split));
	free_split(split);
	*error = 0;
	*cone = obj;
}
