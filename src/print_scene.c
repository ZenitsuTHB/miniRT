/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:31:34 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/02 10:45:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>

static void	print_planes(t_plane *s)
{
	int	i;

	if (!s)
		return ;
	while (s->prev)
		s = s->prev;
	i = 1;
	while (s)
	{
		printf("Plano %d:\n\n", i);
		printf("Pos x: %lf\n", s->origin.x);
		printf("Pos y: %lf\n", s->origin.y);
		printf("Pos z: %lf\n", s->origin.z);
		printf("Normal x: %lf\n", s->normal.x);
		printf("Normal y: %lf\n", s->normal.y);
		printf("Normal z: %lf\n", s->normal.z);
		printf("Color red: %lf\n", s->color.x);
		printf("Color green: %lf\n", s->color.y);
		printf("Color blue: %lf\n", s->color.z);
		printf("\n");
		i++;
		s = s->next;
	}
}

static void	print_cylinders(t_cylinder *s)
{
	int	i;

	if (!s)
		return ;
	while (s->prev)
		s = s->prev;
	i = 1;
	while (s)
	{
		printf("Cylindro %d:\n\n", i);
		printf("Pos x: %lf\n", s->origin.x);
		printf("Pos y: %lf\n", s->origin.y);
		printf("Pos z: %lf\n", s->origin.z);
		printf("Normal x: %lf\n", s->normal.x);
		printf("Normal y: %lf\n", s->normal.y);
		printf("Normal z: %lf\n", s->normal.z);
		printf("Radious: %lf\n", s->radius);
		printf("Height: %lf\n", s->height);
		printf("Color red: %lf\n", s->color.x);
		printf("Color green: %lf\n", s->color.y);
		printf("Color blue: %lf\n", s->color.z);
		printf("\n");
		i++;
		s = s->next;
	}
}

static void	print_cones(t_cone *s)
{
	int	i;

	if (!s)
		return ;
	while (s->prev)
		s = s->prev;
	i = 1;
	while (s)
	{
		printf("Cono %d:\n\n", i);
		printf("Pos x: %lf\n", s->pos.x);
		printf("Pos y: %lf\n", s->pos.y);
		printf("Pos z: %lf\n", s->pos.z);
		printf("Normal x: %lf\n", s->normal.x);
		printf("Normal y: %lf\n", s->normal.y);
		printf("Normal z: %lf\n", s->normal.z);
		printf("Radious: %lf\n", s->radius);
		printf("Height: %lf\n", s->height);
		printf("Color red: %lf\n", s->color.x);
		printf("Color green: %lf\n", s->color.y);
		printf("Color blue: %lf\n", s->color.z);
		printf("\n");
		i++;
		s = s->next;
	}
}

static void	print_spheres(t_sphere *s)
{
	int	i;

	if (!s)
		return ;
	while (s->prev)
		s = s->prev;
	i = 1;
	while (s)
	{
		printf("Esfera %d:\n\n", i);
		printf("Pos x: %lf\n", s->pos.x);
		printf("Pos y: %lf\n", s->pos.y);
		printf("Pos z: %lf\n", s->pos.z);
		printf("Radious: %lf\n", s->radius);
		printf("Color red: %lf\n", s->color.x);
		printf("Color green: %lf\n", s->color.y);
		printf("Color blue: %lf\n", s->color.z);
		printf("\n");
		i++;
		s = s->next;
	}
}

static void	print_lights(t_light *s)
{
	int	i;

	if (!s)
		return ;
	while (s->prev)
		s = s->prev;
	i = 1;
	while (s)
	{
		printf("Light(L): \n\n");
		printf("Pos x: %lf\n", s->pos.x);
		printf("Pos y: %lf\n", s->pos.y);
		printf("Pos z: %lf\n", s->pos.z);
		printf("Bright: %lf\n", s->bright);
		printf("Color red: %lf\n", s->color.x);
		printf("Color blue: %lf\n", s->color.z);
		printf("Color green: %lf\n\n", s->color.y);
		i++;
		s = s->next;
	}
}

void	print_scene(t_scene scene)
{
	printf("Ambient(A): \n\n");
	printf("Ratio: %lf\n", scene.ambient->ratio);
	printf("Color red: %lf\n", scene.ambient->color.x);
	printf("Color blue: %lf\n", scene.ambient->color.z);
	printf("Color green: %lf\n\n", scene.ambient->color.y);
	printf("Camera(C): \n\n");
	printf("Pos x: %lf\n", scene.camera->pos.x);
	printf("Pos y: %lf\n", scene.camera->pos.y);
	printf("Pos z: %lf\n", scene.camera->pos.z);
	printf("Normal x: %lf\n", scene.camera->normal.x);
	printf("Normal y: %lf\n", scene.camera->normal.y);
	printf("Normal z: %lf\n", scene.camera->normal.z);
	printf("Fov: %d\n\n", scene.camera->fov);
	print_lights(scene.light);
	print_spheres(scene.spheres);
	print_planes(scene.planes);
	print_cylinders(scene.cylinders);
	print_cones(scene.cones);
}
