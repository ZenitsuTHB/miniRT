/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:31:34 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/30 16:48:07 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/struct.h"
#include <stdio.h>

void	print_planes(t_plane *s)
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
		printf("Pos x: %lf\n", s->pos.x);
		printf("Pos y: %lf\n", s->pos.y);
		printf("Pos z: %lf\n", s->pos.z);
		printf("Normal x: %lf\n", s->normal.x);
		printf("Normal y: %lf\n", s->normal.y);
		printf("Normal z: %lf\n", s->normal.z);
		printf("Color red: %d\n", s->color.red);
		printf("Color green: %d\n", s->color.green);
		printf("Color blue: %d\n", s->color.blue);
		printf("Color: %u\n", s->color.hex_color);
		printf("\n");
		i++;
		s = s->next;
	}
}

void	print_cylinders(t_cylinder *s)
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
		printf("Pos x: %lf\n", s->pos.x);
		printf("Pos y: %lf\n", s->pos.y);
		printf("Pos z: %lf\n", s->pos.z);
		printf("Normal x: %lf\n", s->normal.x);
		printf("Normal y: %lf\n", s->normal.y);
		printf("Normal z: %lf\n", s->normal.z);
		printf("Diameter: %lf\n", s->diameter);
		printf("Height: %lf\n", s->height);
		printf("Color red: %d\n", s->color.red);
		printf("Color green: %d\n", s->color.green);
		printf("Color blue: %d\n", s->color.blue);
		printf("Color: %u\n", s->color.hex_color);
		printf("\n");
		i++;
		s = s->next;
	}
}

void	print_cones(t_cone *s)
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
		printf("Diameter: %lf\n", s->diameter);
		printf("Height: %lf\n", s->height);
		printf("Color red: %d\n", s->color.red);
		printf("Color green: %d\n", s->color.green);
		printf("Color blue: %d\n", s->color.blue);
		printf("Color: %u\n", s->color.hex_color);
		printf("\n");
		i++;
		s = s->next;
	}
}

void	print_spheres(t_sphere *s)
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
		printf("Diameter: %lf\n", s->diameter);
		printf("Color red: %d\n", s->color.red);
		printf("Color green: %d\n", s->color.green);
		printf("Color blue: %d\n", s->color.blue);
		printf("Color: %u\n", s->color.hex_color);
		printf("\n");
		i++;
		s = s->next;
	}
}

void	print_scene(t_scene scene)
{
	printf("Ambient(A): \n\n");
	printf("Ratio: %lf\n", scene.ambient->ratio);
	printf("Color red: %d\n", scene.ambient->color.red);
	printf("Color blue: %d\n", scene.ambient->color.blue);
	printf("Color green: %d\n", scene.ambient->color.green);
	printf("Color: %u\n\n", scene.ambient->color.hex_color);
	printf("Camera(C): \n\n");
	printf("Pos x: %lf\n", scene.camera->pos.x);
	printf("Pos y: %lf\n", scene.camera->pos.y);
	printf("Pos z: %lf\n", scene.camera->pos.z);
	printf("Normal x: %lf\n", scene.camera->normal.x);
	printf("Normal y: %lf\n", scene.camera->normal.y);
	printf("Normal z: %lf\n", scene.camera->normal.z);
	printf("Fov: %d\n\n", scene.camera->fov);
	printf("Light(L): \n\n");
	printf("Pos x: %lf\n", scene.light->pos.x);
	printf("Pos y: %lf\n", scene.light->pos.y);
	printf("Pos z: %lf\n", scene.light->pos.z);
	printf("Bright: %lf\n", scene.light->bright);
	printf("Color red: %d\n", scene.light->color.red);
	printf("Color blue: %d\n", scene.light->color.blue);
	printf("Color green: %d\n", scene.light->color.green);
	printf("Color: %u\n\n", scene.light->color.hex_color);
	print_spheres(scene.spheres);
	print_planes(scene.planes);
	print_cylinders(scene.cylinders);
	print_cones(scene.cones);
}
