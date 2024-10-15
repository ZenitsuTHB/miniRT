/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:31:34 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/15 13:17:32 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>

/* static void	print_planes(t_plane *s)
{
	static int	i = 1;

	if (!s)
		return ;
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
}

static void	print_cylinders(t_cylinder *s)
{
	static int	i = 1;

	if (!s)
		return ;
	printf("Cylindro %d:\n\n", i);
	printf("Pos x: %lf\n", s->pos.x);
	printf("Pos y: %lf\n", s->pos.y);
	printf("Pos z: %lf\n", s->pos.z);
	printf("Normal x: %lf\n", s->normal.x);
	printf("Normal y: %lf\n", s->normal.y);
	printf("Normal z: %lf\n", s->normal.z);
	printf("Radious: %lf\n", s->radius);
	printf("Height: %lf\n", s->height);
	printf("Color red: %d\n", s->color.red);
	printf("Color green: %d\n", s->color.green);
	printf("Color blue: %d\n", s->color.blue);
	printf("\n");
	i++;
}

static void	print_cones(t_cone *s)
{
	static int	i = 1;

	if (!s)
		return ;
	printf("Cono %d:\n\n", i);
	printf("Pos x: %lf\n", s->pos.x);
	printf("Pos y: %lf\n", s->pos.y);
	printf("Pos z: %lf\n", s->pos.z);
	printf("Normal x: %lf\n", s->normal.x);
	printf("Normal y: %lf\n", s->normal.y);
	printf("Normal z: %lf\n", s->normal.z);
	printf("Radious: %lf\n", s->radius);
	printf("Height: %lf\n", s->height);
	printf("Color red: %d\n", s->color.red);
	printf("Color green: %d\n", s->color.green);
	printf("Color blue: %d\n", s->color.blue);
	printf("\n");
	i++;
}
 */
static void	print_spheres(t_sphere *s)
{
	static int	i = 1;

	if (!s)
		return ;
	printf("Esfera %d:\n\n", i);
	printf("Pos x: %lf\n", s->center.x);
	printf("Pos y: %lf\n", s->center.y);
	printf("Pos z: %lf\n", s->center.z);
	printf("Radious: %lf\n", s->radius);
	printf("Color red: %d\n", s->color.red);
	printf("Color green: %d\n", s->color.green);
	printf("Color blue: %d\n", s->color.blue);
	printf("\n");
	i++;
}

void	print_scene(t_scene scene)
{
	t_obj	*obj;

	/* printf("Ambient(A): \n\n");
	printf("Ratio: %lf\n", scene.ambient->bright);
	printf("Color red: %d\n", scene.ambient->color.red);
	printf("Color blue: %d\n", scene.ambient->color.blue);
	printf("Color green: %d\n\n", scene.ambient->color.green); */
	printf("Camera(C): \n\n");
	printf("Pos x: %lf\n", scene.camera->origin.x);
	printf("Pos y: %lf\n", scene.camera->origin.y);
	printf("Pos z: %lf\n", scene.camera->origin.z);
	printf("cam_dir x: %lf\n", scene.camera->cam_dir.x);
	printf("cam_dir y: %lf\n", scene.camera->cam_dir.y);
	printf("cam_dir z: %lf\n", scene.camera->cam_dir.z);
	printf("Fov: %d\n\n", scene.camera->fov);
	/* printf("Light(L): \n\n");
	printf("Pos x: %lf\n", scene.light->pos.x);
	printf("Pos y: %lf\n", scene.light->pos.y);
	printf("Pos z: %lf\n", scene.light->pos.z);
	printf("Bright: %lf\n", scene.light->bright);
	printf("Color red: %d\n", scene.light->color.red);
	printf("Color blue: %d\n", scene.light->color.blue);
	printf("Color green: %d\n\n", scene.light->color.green); */
	obj = scene.obj;
	if (!obj)
		return ;
	while (obj->prev)
		obj = obj->prev;
	while (obj)
	{
		if (obj->id == SP)
			print_spheres(obj->shape.sp);
		/* else if (obj->shape.pl)
			print_planes(obj->shape.pl);
		else if (obj->shape.cy)
			print_cylinders(obj->shape.cy);
		else if (obj->shape.co)
			print_cones(obj->shape.co); */
		obj = obj->next;
	}
}
