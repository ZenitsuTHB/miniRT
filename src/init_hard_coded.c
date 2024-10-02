/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hard_coded.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:48:22 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 20:09:26 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

t_sphere *init_sphere(t_vec3 center, t_rgb color, double radius)
{
  t_sphere *sp;

  sp = malloc(sizeof(t_sphere));
  if (!sp)
    return (NULL);
  printf("var  %lf %lf %lf \n", center.x, center.y, center.z);
  sp->radius = radius;
  sp->center = center;
  sp->color = create_vec3(color.x, color.y, color.z);
  return (sp);
}

t_objects *set_objjj(t_scene *scene, int type)
{
  t_objects *obj;


  printf("hit obj = %p %p\n", scene->hit->object, scene->hit->object->next);
  obj = scene->hit->object;
  obj->shape = malloc(sizeof(t_shape));
  if (type == SP)
  {
    obj->type = type;
    obj->shape->sp = scene->spheres;
  }
  obj->next = NULL;
  printf("hit obj = %p %p\n", scene->hit->object, scene->hit->object->next);
  return (obj);
}

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
		//INTERSECTIONS
  scene->hit = malloc(sizeof(t_hit));
  if (!scene->hit)
    return (error_message(RED, MALLOC_ERROR));
  scene->hit->t = INFINITY;
  scene->hit->point = (t_vec3){0.0, 0.0, 0.0};
  scene->hit->normal = (t_vec3){0.0, 0.0, 0.0};
   // PLANES
	scene->planes = malloc(sizeof(t_plane));
	if (!scene->planes)
		return (error_message(RED, MALLOC_ERROR));
	scene->planes->origin = (t_vec3){0.0, 0.0, -10.0};
	scene->planes->normal = (t_vec3){0.0, 1.0, 0.0};
	scene->planes->color = create_vec3(0.2, 0.5, 0.3);
  //SPHERE
  scene->spheres = init_sphere((t_vec3){0.0, 0.0, 20.6}, (t_rgb){1.0, 0.0, 0.0}, 5.6);
  if (!scene->spheres)
    return(error_message(RED, MALLOC_ERROR));
  //OBJECT
  scene->hit->object = malloc(sizeof(t_objects));
  scene->hit->object = set_objjj(scene, SP);
  if (!scene->hit->object)
    return(error_message(RED, MALLOC_ERROR));
  printf("scene->sphere = %p\n", scene->spheres);
  printf("scene->spherehit = %p\n", scene->hit->object->shape->sp);
  // scene->hit->object->next = malloc(sizeof(t_objects));
  // scene->spheres = init_sphere((t_vec3){10.0, 0.0, 20.6}, (t_rgb){0.0, 2.0, 0.0}, 3.6);
  // if (!scene->spheres)
  //   return(error_message(RED, MALLOC_ERROR));
  // scene->hit->object->next = set_objjj(scene, SP);
  // if (!scene->hit->object)
  //   return(error_message(RED, MALLOC_ERROR));
  return (0);
}
