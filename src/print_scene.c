/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:31:34 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/14 22:37:39 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	print_planes(t_plane *s)
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
	printf("Color red: %lf\n", s->color.x);
	printf("Color green: %lf\n", s->color.y);
	printf("Color blue: %lf\n", s->color.z);
	printf("\n");
	i++;
}

void print_vec3(t_vec3 v)
{
	printf("vector x --- [%lf]\t", v.x);
	printf("vector y --- [%lf]\t", v.y);
	printf("vector z --- [%lf]\n", v.z);
}

void	print_cylinders(t_cylinder *s)
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
	printf("Color red: %lf\n", s->color.x);
	printf("Color green: %lf\n", s->color.y);
	printf("Color blue: %lf\n", s->color.z);
	printf("\n");
	i++;
}

void	print_cones(t_cone *s)
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
	printf("Color red: %lf\n", s->color.x);
	printf("Color green: %lf\n", s->color.y);
	printf("Color blue: %lf\n", s->color.z);
	printf("\n");
	i++;
}
 
void	print_spheres(t_sphere *s)
{
	static int	i = 1;

	if (!s)
		return ;
	printf("Esfera %d:\n\n", i);
	printf("Pos x: %lf\n", s->center.x);
	printf("Pos y: %lf\n", s->center.y);
	printf("Pos z: %lf\n", s->center.z);
	printf("Radious: %lf\n", s->radius);
	printf("Color red: %lf\n", s->color.x);
	printf("Color green: %lf\n", s->color.y);
	printf("Color blue: %lf\n", s->color.z);
	printf("\n");
	i++;
}

void	print_scene(t_scene scene)
{
	t_obj	*obj;

	printf("Ambient(A): \n\n");
	printf("Ratio: %lf\n", scene.ambient->bright);
	printf("Color red: %lf\n", scene.ambient->color.x);
	printf("Color blue: %lf\n", scene.ambient->color.y);
	printf("Color green: %lf\n\n", scene.ambient->color.z); 
	printf("Camera(C): \n\n");
	printf("Pos x: %lf\n", scene.camera->origin.x);
	printf("Pos y: %lf\n", scene.camera->origin.y);
	printf("Pos z: %lf\n", scene.camera->origin.z);
	printf("cam_dir x: %lf\n", scene.camera->cam_dir.x);
	printf("cam_dir y: %lf\n", scene.camera->cam_dir.y);
	printf("cam_dir z: %lf\n", scene.camera->cam_dir.z);
	printf("Fov: %d\n\n", scene.camera->fov);
	 printf("Light(L): \n\n");
	printf("Pos x: %lf\n", scene.light->pos.x);
	printf("Pos y: %lf\n", scene.light->pos.y);
	printf("Pos z: %lf\n", scene.light->pos.z);
	printf("Bright: %lf\n", scene.light->bright);
	printf("Color red: %lf\n", scene.light->color.x);
	printf("Color blue: %lf\n", scene.light->color.y);
	printf("Color green: %lf\n\n", scene.light->color.z); 
	obj = scene.obj;
	if (!obj)
		return ;
	while (obj->prev)
		obj = obj->prev;
	while (obj)
	{
		if (obj->id == SP)
			print_spheres(obj->shape.sp);
		if (obj->id == PL)
			print_planes(obj->shape.pl);
		if (obj->id == CY)
			print_cylinders(obj->shape.cy);
		if (obj->id == CO)
			print_cones(obj->shape.co); 
		obj = obj->next;
	}
}
