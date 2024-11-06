/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:04:37 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/06 14:19:33 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	put_zero(int *var)
{
	*var = 0;
}

t_sphere	*get_sphere(int id, char *data, int *error)
{
	t_sphere	*obj;
	char		**split;
	char		*err;

	obj = malloc(sizeof(t_sphere));
	if (!obj)
		return (error_parser(YEL, MSG_MEM), NULL);
	if (id != SP)
		return (free(obj), put_zero(error), NULL);
	split = ft_splitset(data, " \t");
	if (!split)
		return (free(obj), error_parser(YEL, MSG_MEM), NULL);
	if (ft_splitlen(split) != 4)
		return (free(obj), free_split(split), error_parser(YEL, MSG_DATA),
			NULL);
	if (set_pos(split[1], &(obj->center)))
		return (free(obj), free_split(split), NULL);
	obj->radius = ft_strtod(split[2], &err) / 2;
	if (*err)
		return (free(obj), free_split(split), NULL);
	if (set_color(split[3], &obj->color))
		return (free(obj), free_split(split), NULL);
	return (free_split(split), put_zero(error), obj);
}

t_plane	*get_plane(int id, char *data, int *error)
{
	t_plane	*obj;
	char	**split;

	obj = malloc(sizeof(t_plane));
	if (!obj)
		return (error_parser(YEL, MSG_MEM), NULL);
	if (id != PL)
		return (free(obj), put_zero(error), NULL);
	split = ft_splitset(data, " \t");
	if (!split)
		return (free(obj), error_parser(YEL, MSG_MEM), NULL);
	if (ft_splitlen(split) != 4)
		return (free(obj), free_split(split), error_parser(YEL, MSG_DATA),
			NULL);
	if (set_pos(split[1], &obj->pos) || set_normal(split[2], &obj->normal))
		return (free(obj), free_split(split), NULL);
	if (set_color(split[3], &obj->color))
		return (free(obj), free_split(split), NULL);
	return (free_split(split), put_zero(error), obj);
}

t_cylinder	*get_cylinder(int id, char *data, int *error)
{
	t_cylinder	*obj;
	char		**split;
	char		*err;

	obj = malloc(sizeof(t_cylinder));
	if (!obj)
		return (error_parser(YEL, MSG_MEM), NULL);
	if (id != CY)
		return (free(obj), put_zero(error), NULL);
	split = ft_splitset(data, " \t");
	if (!split)
		return (free(obj), error_parser(YEL, MSG_MEM), NULL);
	if (ft_splitlen(split) != 6)
		return (free(obj), free_split(split), error_parser(YEL, MSG_DATA),
			NULL);
	if (set_pos(split[1], &obj->pos) || set_normal(split[2], &obj->normal))
		return (free(obj), free_split(split), NULL);
	obj->radius = ft_strtod(split[3], &err) / 2;
	if (*err)
		return (free(obj), free_split(split), NULL);
	obj->height = ft_strtod(split[4], &err);
	if (*err)
		return (free(obj), free_split(split), NULL);
	if (set_color(split[5], &obj->color))
		return (free(obj), free_split(split), NULL);
	return (free_split(split), put_zero(error), obj);
}

t_cone	*get_cone(int id, char *data, int *error)
{
	t_cone	*obj;
	char	**split;
	char	*err;

	obj = malloc(sizeof(t_cone));
	if (!obj)
		return (error_parser(YEL, MSG_MEM), NULL);
	if (id != CO)
		return (free(obj), put_zero(error), NULL);
	split = ft_splitset(data, " \t");
	if (!split)
		return (free(obj), error_parser(YEL, MSG_MEM), NULL);
	if (ft_splitlen(split) != 6)
		return (free(obj), free_split(split), error_parser(YEL, MSG_DATA),
			NULL);
	if (set_pos(split[1], &obj->pos) || set_normal(split[2], &obj->normal))
		return (free(obj), free_split(split), NULL);
	obj->radius = ft_strtod(split[3], &err) / 2;
	if (*err)
		return (free(obj), free_split(split), NULL);
	obj->height = ft_strtod(split[4], &err);
	if (*err)
		return (free(obj), free_split(split), NULL);
	if (set_color(split[5], &obj->color))
		return (free(obj), free_split(split), NULL);
	return (free_split(split), put_zero(error), obj);
}
