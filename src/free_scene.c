/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:46:40 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 12:42:15 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/struct.h"
#include <stdlib.h>
#include <stdio.h>

void	free_spheres(t_sphere *obj)
{
	void		*next;

	while (obj->prev)
		obj = obj->prev;
	while (obj)
	{
		next = obj->next;
		free(obj);
		obj = next;
	}
}

void	free_planes(t_plane *obj)
{
	void		*next;

	while (obj->prev)
		obj = obj->prev;
	while (obj)
	{
		next = obj->next;
		free(obj);
		obj = next;
	}
}

void	free_cylinders(t_cylinder *obj)
{
	void		*next;

	while (obj->prev)
		obj = obj->prev;
	while (obj)
	{
		next = obj->next;
		free(obj);
		obj = next;
	}
}

void	free_cones(t_cone *obj)
{
	void		*next;

	while (obj->prev)
		obj = obj->prev;
	while (obj)
	{
		next = obj->next;
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
	if (scene->spheres)
		free_spheres(scene->spheres);
	if (scene->planes)
		free_planes(scene->planes);
	if (scene->cylinders)
		free_cylinders(scene->cylinders);
	if (scene->cones)
		free_cones(scene->cones);
}
