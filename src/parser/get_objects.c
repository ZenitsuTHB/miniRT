/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:04:37 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/17 19:20:10 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	put_zero(int *var)
{
	*var = 0;
}

t_sphere	*get_sphere(char *data, int *error)
{
	t_sphere	*obj;
	char		**split;
	char		*err;

	obj = malloc(sizeof(t_sphere));
	if (!obj)
		return (error_parser(YEL, MSG_MEM), NULL);
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

t_plane	*get_plane(char *data, int *error)
{
	t_plane	*obj;
	char	**split;

	obj = malloc(sizeof(t_plane));
	if (!obj)
		return (error_parser(YEL, MSG_MEM), NULL);
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

t_cylinder	*get_cylinder(char *data, int *error)
{
	t_cylinder	*obj;
	char		**sp;
	char		*err;

	obj = malloc(sizeof(t_cylinder));
	if (!obj)
		return (error_parser(YEL, MSG_MEM), NULL);
	sp = ft_splitset(data, " \t");
	if (!sp)
		return (free(obj), error_parser(YEL, MSG_MEM), NULL);
	if (ft_splitlen(sp) != 6)
		return (free(obj), free_split(sp), error_parser(YEL, MSG_DATA), NULL);
	if (set_pos(sp[1], &obj->pos) || set_normal(sp[2], &obj->normal))
		return (free(obj), free_split(sp), NULL);
	obj->radius = ft_strtod(sp[3], &err) / 2;
	if (*err)
		return (free(obj), free_split(sp), NULL);
	obj->height = ft_strtod(sp[4], &err);
	if (*err)
		return (free(obj), free_split(sp), NULL);
	if (set_color(sp[5], &obj->color))
		return (free(obj), free_split(sp), NULL);
	return (free_split(sp), put_zero(error), obj);
}

t_cone	*get_cone(char *data, int *error)
{
	t_cone	*obj;
	char	**sp;
	char	*err;

	obj = malloc(sizeof(t_cone));
	if (!obj)
		return (error_parser(YEL, MSG_MEM), NULL);
	sp = ft_splitset(data, " \t");
	if (!sp)
		return (free(obj), error_parser(YEL, MSG_MEM), NULL);
	if (ft_splitlen(sp) != 6)
		return (free(obj), free_split(sp), error_parser(YEL, MSG_DATA), NULL);
	if (set_pos(sp[1], &obj->pos) || set_normal(sp[2], &obj->normal))
		return (free(obj), free_split(sp), NULL);
	obj->radius = ft_strtod(sp[3], &err) / 2;
	if (*err)
		return (free(obj), free_split(sp), NULL);
	obj->height = ft_strtod(sp[4], &err);
	if (*err || set_color(sp[5], &obj->color))
		return (free(obj), free_split(sp), NULL);
	obj->angle = atan(obj->radius / obj->height);
	obj->tan_squared = pow(obj->radius / obj->height, 2);
	obj->base_center = add_vec3(obj->pos, scalar_mult(obj->normal, obj->height));
	return (free_split(sp), put_zero(error), obj);
}
