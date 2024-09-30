/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/23 17:35:47 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

#define MALLOC_ERROR "Allocation Failed !!!"
#define RENDER_ERROR "Failed to Render_Image"

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
	scene->camera->cam_dir = (t_vec3){0.0, 0.0, -1};
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
  scene->spheres->radius = 12.6; 	
  scene->spheres->center = (t_vec3){0.0, 0.0, 20.6};
	 //INTERSECTIONS
  scene->hit = malloc(sizeof(t_hit));
  if (!scene->hit)
    return (error_message(RED, MALLOC_ERROR));
  scene->hit->t = 2.0;
  scene->hit->point = (t_vec3){0.0, 0.0, 0.0};
  scene->hit->normal = (t_vec3){0.0, 0.0, 0.0};
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
