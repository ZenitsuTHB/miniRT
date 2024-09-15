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

t_rgb ray_color(const t_ *ray)
{
	double a;
	t_rgb blue;
	t_rgb white;
    t_vec3 unit_direction;
	
	unit_direction = unit_vec3(ray->direction);
    a = 0.5 * (unit_direction.y + 1.0);
    
    white = create_vect(1.0, 1.0, 1.0);
    blue = create_vect(0.5, 0.7, 1.0);

    return adding_vect(scalar_mult(white, 1.0 - a), scalar_mult(blue, a));
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
