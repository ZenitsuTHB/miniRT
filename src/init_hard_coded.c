/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hard_coded.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:48:22 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 23:00:36 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

	// // CAMERA
	// scene->camera = malloc(sizeof(t_camera));
	// if (!scene->camera)
	// 	return (error_message(RED, MALLOC_ERROR));
	// scene->camera->fov = 70;
	// scene->camera->focal_len = 1.0;
	// scene->camera->ratio = WIDTH / HEIGHT;
	// scene->camera->pos = (t_vec3){-50.0, 0.0, 20.0};
	// scene->camera->cam_dir = unit_vec3(substract_vec3((t_vec3){0.0, 0.0, 20.6}, scene->camera->pos));
	// //scene->camera->cam_dir = (t_vec3){0.0, 0.0, 0.0};
	// scene->camera->normal = (t_vec3){0.0, 0.0, 1.0};

int	init_scene(t_scene *scene)
{
	ft_bzero(scene, sizeof(t_scene));
	scene->mlx = malloc(sizeof(t_mlx));
	if (!scene->mlx)
		return (error_message(RED, MALLOC_ERROR));
  return (0);
}
