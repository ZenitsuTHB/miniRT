/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:34:09 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/23 13:21:45 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static t_obj	*get_new_obj(t_obj *prev, int id)
{
	t_obj	*obj;

	obj = malloc(sizeof(t_obj));
	if (!obj)
		return (error_parser(YEL, MSG_MEM), NULL);
	obj->id = id;
	obj->next = NULL;
	if (!prev)
		obj->prev = NULL;
	else
	{
		obj->prev = prev;
		prev->next = obj;
	}
	return (obj);
}

static int	add_object(t_obj **obj, int id, char *data)
{
	int		error;
	t_obj	*new;

	error = 1;
	new = get_new_obj(*obj, id);
	if (!new)
		return (1);
	if (id == SP)
		new->shape.sp = get_sphere(data, &error);
	else if (id == PL)
		new->shape.pl = get_plane(data, &error);
	else if (id == CY)
		new->shape.cy = get_cylinder(data, &error);
	else if (id == CU)
		new->shape.cu = get_cube(data, &error);
	*obj = new;
	return (error);
}

void	set_object(t_scene *scene, char *id, char *data, int *error)
{
	int	status;

	if (!ft_strncmp(id, "sp", 3))
		status = add_object(&(scene->obj), SP, data);
	else if (!ft_strncmp(id, "pl", 3))
		status = add_object(&(scene->obj), PL, data);
	else if (!ft_strncmp(id, "cy", 3))
		status = add_object(&(scene->obj), CY, data);
	else if (!ft_strncmp(id, "cu", 3))
		status = add_object(&(scene->obj), CU, data);
	else
	{
		printf(RED "\n\tError\n" YEL "\t%s%s\n\n" NC, MSG_OBJ, id);
		return ;
	}
	*error = status;
}
