/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:59:36 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/13 20:59:58 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"
# include <../libs/MLX42/include/MLX42/MLX42.h>

int	render_object(t_scene *scene)
{
	t_mlx mlx;

	mlx.x = 0.0;
	while (mlx.x < WIDTH)
	{
   		mlx.y = 0.0;
		while (mlx.y < HEIGHT)
		{
			scene->planes->normal = create_vect(mlx.x / 2, (mlx.y / 2), 0.0);
      		mlx_put_pixel(mlx.img, mlx.x, mlx.y, gradient_color(ray_color(scene)));
			mlx.y++;
		}
		mlx.x++;
	}
	//int radius = 200;
//	draw_sphere(mlx, WIDTH / 2, HEIGHT / 2, radius);
	mlx_image_to_window(mlx.con, mlx.img, 0, 0);
	


	return (0);
}
