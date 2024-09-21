/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:45:16 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/21 13:24:48 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	error_message(char *color, char *msg)
{
	printf(RED"\n\tError\n");
	printf("\t%s%s\n\n"NC, color, msg);
	return (-1);
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
}

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (read_file(argc, argv[1], &scene))
		return (1);
	print_scene(scene);
	return (EXIT_SUCCESS);
}
