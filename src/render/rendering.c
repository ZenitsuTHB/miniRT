/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:59:36 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/11 22:37:54 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>
/* 
t_vec3	get_pixel_direction(int x, int y)
{
	double	x_ndc;
	double	y_ndc;

	//Converting the pixel coordinates into Normalized Device Coordinates(NDC)

	x_ndc = 
} */

int	render_object(t_scene *scene)
{
	t_mlx	*mlx;
	//t_vec3	px_direction;

	// init_ray(scene->camera, scene->ray);
	setting_up_camera(scene->camera);
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
			//px_direction = get_pixel_direction(mlx->x, mlx->y);
			mlx_put_pixel(mlx->img, mlx->x, mlx->y, 0x0);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_image_to_window(mlx->con, mlx->img, 0, 0);
	return (0);
}
