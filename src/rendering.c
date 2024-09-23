/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:59:36 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/15 21:47:24 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"
# include <../libs/MLX42/include/MLX42/MLX42.h>

t_rgb ray_color(int y, int height)
{
    double  t;
    t_rgb   blue;
    t_rgb   white;
    
    t = (double)y / (height - 1);
    white = create_vec3(1.0, 1.0, 1.0);
    blue = create_vec3(0.5, 0.7, 1.0);
    return add_vec3(scalar_mult(white, t), scalar_mult(blue, 1.0 - t));
}

uint32_t gradient_color(t_rgb color)
{
	  uint8_t r = (int)(color.x * 255.99);
    uint8_t g = (int)(color.y * 255.99);
    uint8_t b = (int)(color.z * 255.99);

    return (r << 24 | g << 16 | b << 8 | 255); // Returning as RGBA format
}

int	render_object(t_scene *scene)
{
	t_mlx *mlx;

	if (init_window(scene->mlx))
		return (error_message( YEL ,ERROR_WIND));
  if (setting_camera(scene->camera))
    return (error_message(YEL, "Failed to setting up camera."));
  mlx = scene->mlx;
	mlx->x = 0;
	while (mlx->x < WIDTH)
	{
    mlx->y = 0;
		while (mlx->y < HEIGHT)
		{
      generate_ray(scene->camera, scene->ray, mlx->x, mlx->y);
      t_rgb color = ray_color(mlx->y, HEIGHT);
      mlx_put_pixel(mlx->img, mlx->x, mlx->y, gradient_color(color));
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_image_to_window(mlx->con, mlx->img, 0, 0);
	return (0);
}
