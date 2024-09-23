/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:45:16 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/23 17:11:38 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

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
		
		printf("\n");

		i++;
		s = s->next;
	}
}

void print_spheres(t_sphere *s)
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
		
		printf("\n");

		i++;
		s = s->next;
	}
}

void print_scene(t_scene scene)
{

	printf("Ambient(A): \n\n");
	
	printf("Ratio: %lf\n", scene.ambient->ratio);
	
	printf("Color red: %d\n", scene.ambient->color.red);
	printf("Color blue: %d\n", scene.ambient->color.blue);
	printf("Color green: %d\n", scene.ambient->color.green);
	
	printf("\n");
	

	printf("Camera(C): \n\n");
	
	printf("Pos x: %lf\n", scene.camera->pos.x);
	printf("Pos y: %lf\n", scene.camera->pos.y);
	printf("Pos z: %lf\n", scene.camera->pos.z);
	
	printf("Normal x: %lf\n", scene.camera->normal.x);
	printf("Normal y: %lf\n", scene.camera->normal.y);
	printf("Normal z: %lf\n", scene.camera->normal.z);
	
	printf("Fov: %lf\n", scene.camera->fov);

	printf("\n");
	

	printf("Light(L): \n\n");

	printf("Pos x: %lf\n", scene.light->pos.x);
	printf("Pos y: %lf\n", scene.light->pos.y);
	printf("Pos z: %lf\n", scene.light->pos.z);

	printf("Bright: %lf\n", scene.light->bright);

	printf("Color red: %d\n", scene.light->color.red);
	printf("Color blue: %d\n", scene.light->color.blue);
	printf("Color green: %d\n", scene.light->color.green);
	
	printf("\n");

	print_spheres(scene.spheres);
	print_planes(scene.planes);
	print_cylinders(scene.cylinders);
	print_cones(scene.cones);
}

int	error_message(char *color, char *msg)
{
	printf(RED"\n\tError\n");
	printf("\t%s%s\n\n"NC, color, msg);
	return (-1);
}

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (read_file(argc, argv[1], &scene))
		return (EXIT_FAILURE);

	//print_scene(scene);
	return (EXIT_SUCCESS);
}
