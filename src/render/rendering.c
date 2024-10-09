/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:59:36 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/09 20:12:13 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>


t_vec3	get_pixel_direction()
{
	double x_ndc;
	double y_ndc;

	//
}

int	render_object(t_scene *scene)
{
	t_mlx	*mlx;
	t_vec3	px_direction;
	
	//init_ray(scene->camera, scene->ray);
	//if (setting_camera(scene->camera))
  printf("this is mlx %p\n", scene->mlx);
  if (init_window(scene->mlx))
		return (error_message(YEL, ERROR_WIND));
	mlx = scene->mlx;
	mlx->x = 0;
	while (mlx->x < WIDTH)
	{
		mlx->y = 0;
		while (mlx->y < HEIGHT)
		{
			px_direction = get_pixel_direction(mlx->x, mlx->y);	
      		mlx_put_pixel(mlx->img, mlx->x, mlx->y, 0x0);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_image_to_window(mlx->con, mlx->img, 0, 0);
	return (0);
}
