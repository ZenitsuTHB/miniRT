/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hard_coded.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:48:22 by marvin            #+#    #+#             */
/*   Updated: 2024/09/30 22:48:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

int	init_scene(t_scene *scene)
{
	ft_bzero(scene, sizeof(t_scene));
	scene->mlx = malloc(sizeof(t_mlx));
	if (!scene->mlx)
		return (error_message(RED, MALLOC_ERROR));
			// CAMERA
	scene->camera = malloc(sizeof(t_camera));
	if (!scene->camera)
		return (error_message(RED, MALLOC_ERROR));
	scene->camera->fov = 70;
	scene->camera->focal_len = 1.0;
	scene->camera->ratio = WIDTH / HEIGHT;
	scene->camera->pos = (t_vec3){-50.0, 0.0, 20.0};
	scene->camera->cam_dir = unit_vec3(substract_vec3((t_vec3){0.0, 0.0, 20.6}, scene->camera->pos));
	//scene->camera->cam_dir = (t_vec3){0.0, 0.0, 0.0};
	scene->camera->normal = (t_vec3){0.0, 0.0, 1.0};
  // RAY
	scene->ray = malloc(sizeof(t_ray));
	if (!scene->ray)
		return (error_message(RED, MALLOC_ERROR));
   // PLANES
	scene->planes = malloc(sizeof(t_plane));
	if (!scene->planes)
		return (error_message(RED, MALLOC_ERROR));
	scene->planes->origin = (t_vec3){0.0, 0.0, -10.0};
	scene->planes->normal = (t_vec3){0.0, 1.0, 0.0};
	scene->planes->color = create_vec3(0.2, 0.5, 0.3);
	//SPHERE
  scene->spheres = malloc(sizeof(t_sphere));
  if (!scene->spheres)
    return(error_message(RED, MALLOC_ERROR));
  scene->spheres->radius = 5.6; 	
  scene->spheres->center = (t_vec3){0.0, 0.0, 20.6};
  scene->spheres->color = create_vec3(1.0, 0.0, 0.0);
  scene->spheres->next = malloc(sizeof(t_sphere));
  if (!scene->spheres->next)
    return(error_message(RED, MALLOC_ERROR));
  scene->spheres->next->radius = 4.6; 	
  scene->spheres->next->center = (t_vec3){0.0, 0.0, 10.6};
  scene->spheres->next->color = create_vec3(1.0, 0.0, 1.0);
  scene->spheres->next->next = NULL;
	//INTERSECTIONS
  scene->hit = malloc(sizeof(t_hit));
  if (!scene->hit)
    return (error_message(RED, MALLOC_ERROR));
  scene->hit->t = INFINITY;
  scene->hit->point = (t_vec3){0.0, 0.0, 0.0};
  scene->hit->normal = (t_vec3){0.0, 0.0, 0.0};
  //1ST
  scene->hit->object = malloc(sizeof(t_objects));
  if (!scene->hit->object)
  	return(error_message(RED, MALLOC_ERROR));
  scene->hit->object->obj = scene->spheres;
  scene->hit->object->type = SP;
  //2ND
  scene->hit->object->next = malloc(sizeof(t_objects));
  if (!scene->hit->object->next)
  	return(error_message(RED, MALLOC_ERROR));
  printf("the plane address is %p \n", scene->hit->object->next);
  scene->hit->object->next->obj = scene->planes;
  scene->hit->object->next->type = PL;
  //3rd
  scene->hit->object->next->next = malloc(sizeof(t_objects));
  if (!scene->hit->object->next->next)
  	return(error_message(RED, MALLOC_ERROR));
  printf("the new address is %p \n", scene->hit->object->next->next);
  scene->hit->object->next->next->obj = scene->spheres->next;
  scene->hit->object->next->next->type = SP;
  scene->hit->object->next->next->next = NULL;
  return (0);
}