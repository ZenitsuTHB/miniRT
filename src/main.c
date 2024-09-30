/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/30 20:03:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>


int	error_message(char *color, char *msg)
{
	printf(RED "\n\tError\n");
	printf("\t%s%s\n\n" NC, color, msg);
	return (1);
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
	//scene->camera->cam_dir = (t_vec3){0.0, 0.0, -1};
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
	//SPHERE
  scene->spheres = malloc(sizeof(t_sphere));
  if (!scene->spheres)
    return(error_message(RED, MALLOC_ERROR));
  scene->spheres->radius = 8.6; 	
  scene->spheres->center = (t_vec3){0.0, 0.0, 20.6};
  scene->spheres->color = create_vec3(1.0, 0.0, 0.0);
  scene->spheres->next = malloc(sizeof(t_sphere));
  if (!scene->spheres->next)
    return(error_message(RED, MALLOC_ERROR));
  scene->spheres->next->radius = 4.6; 	
  scene->spheres->next->center = (t_vec3){2.0, 0.0, 10.6};
  scene->spheres->next->color = create_vec3(1.0, 0.0, 1.0);
  scene->spheres->next->next = NULL;
	//INTERSECTIONS
  scene->hit = malloc(sizeof(t_hit));
  if (!scene->hit)
    return (error_message(RED, MALLOC_ERROR));
  scene->hit->t = INFINITY;
  scene->hit->point = (t_vec3){0.0, 0.0, 0.0};
  scene->hit->normal = (t_vec3){0.0, 0.0, 0.0};
  scene->hit->object = malloc(sizeof(t_objects));
  if (!scene->hit->object)
  	return(error_message(RED, MALLOC_ERROR));
  scene->hit->object->obj = scene->spheres;
  scene->hit->object->type = SP;
  scene->hit->object->next = NULL;
  return (0);
}
// if (init_window(scene.mlx))
// return (error_message( YEL ,ERROR_WIND));

int	main(int argc, char *argv[])
{
	t_scene	scene;

	(void)argc;
	(void)argv;
	init_scene(&scene);
	if (render_object(&scene))
		return (error_message(YEL, RENDER_ERROR));
	mlx_key_hook(scene.mlx->con, &manage_escape, scene.mlx);
	mlx_loop(scene.mlx->con);
	mlx_terminate(scene.mlx->con);
	exit(0);
	return (EXIT_SUCCESS);
}
