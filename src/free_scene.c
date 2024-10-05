/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:46:40 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/05 11:58:22 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struct.h"
#include <stdlib.h>

void	free_objects(t_obj *obj)
{
	void	*next;

	if (!obj)
		return ;
	while (obj->prev)
		obj = obj->prev;
	while (obj)
	{
		next = obj->next;
		if (obj->shape.sp)
			free(obj->shape.sp);
		if (obj->shape.pl)
			free(obj->shape.pl);
		if (obj->shape.cy)
			free(obj->shape.cy);
		if (obj->shape.co)
			free(obj->shape.co);
		free(obj);
		obj = next;
	}
}

void	free_scene(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->ambient)
		free(scene->ambient);
	if (scene->camera)
		free(scene->camera);
	if (scene->light)
		free(scene->light);
	free_objects(scene->obj);
}
