/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/12 15:35:41 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
# include <../libs/MLX42/include/MLX42/MLX42.h>

void draw_sphere(t_mlx *mlx, int cx, int cy, int radius)
{
    int x, y;
    for (x = -radius; x <= radius; x++)
    {
        for (y = -radius; y <= radius; y++)
        {
            if (x * x + y * y <= radius * radius)
            {
                int z = sqrt(radius * radius - x * x - y * y);
                int brightness = (z * 255) / radius;
                uint32_t pixel_color = (brightness << 24) | (brightness << 16) | 255;
                mlx_put_pixel(mlx->img, cx + x, cy + y, pixel_color);
            }
        }
    }
}


t_rgb ray_color(const t_ray *ray)
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
    // Calculate the interpolation factor (0 at the top, 1 at the bottom)
    //float factor = (float)y / height;

    // Interpolating between blue (0x0000FF) and white (0xFFFFFF)
    //uint8_t r = (uint8_t)(255 * factor);   // Red component increases with factor
    //uint8_t g = (uint8_t)(255 * factor);   // Green component increases with factor
    //uint8_t b = 255;                       // Blue component stays 255
	
	uint8_t r = (int)(color.x * 255.99);
    uint8_t g = (int)(color.y * 255.99);
    uint8_t b = (int)(color.z * 255.99);

    return (r << 24 | g << 16 | b << 8 | 255); // Returning as RGBA format
}

void manage_escape(mlx_key_data_t keydata, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
        printf("Escape key pressed. Exiting...\n");
		//mlx_delete_image(mlx->con, mlx->img->ptr);
		mlx_close_window((mlx->con));
		mlx_terminate(mlx->con);
		exit(0);
    }
    else
    {
        printf("Key pressed: %d\n", keydata.key);
    }
}

int			error_message(char *color, char *msg)
{
	printf(RED"\n\tError\n");
	printf("\t%s%s\n\n"NC, color, msg);
	return (-1);
}

int	init_window(t_scene *scene)
{
	//	sp->center = create_vect(0.0, 0.0, 20.6);
	//	sp->diameter = 12.6;
	
	scene->planes->origin = create_vect(0.0, 0.0, 0.0);
	ray.direction = create_vect(0.0, 0.0, 0.0);

	mlx->con = mlx_init(HEIGHT, WIDTH, "miniRT", false);
	if (mlx->con == NULL)
		return (1);
	mlx->img =  mlx_new_image(mlx->con, WIDTH, HEIGHT);
	if (mlx->img == NULL)
		return (1);
	return (0);
}

int	init_master(t_mlx *mlx)
{
	t_ray scene;

	if (init_window(&scene))
		return (error_message( YEL ,ERROR_WIND));
//	t_sphere sp;

//	sp->center = create_vect(0.0, 0.0, 20.6);
//	sp->diameter = 12.6;
	ray.origin = create_vect(0.0, 0.0, 0.0);
	ray.direction = create_vect(0.0, 0.0, 0.0);

	mlx->con = mlx_init(HEIGHT, WIDTH, "miniRT", false);
	if (mlx->con == NULL)
		return (1);
	mlx->img =  mlx_new_image(mlx->con, WIDTH, HEIGHT);
	if (mlx->img == NULL)
		return (1);
	mlx->x = 0.0;
	while (mlx->x < WIDTH)
	{
   		mlx->y = 0.0;
		while (mlx->y < HEIGHT)
		{
			//double vertical_factor = (double)mlx->y / HEIGHT; // from 0 at top to 1 at bottom
       	 	//double horizontal_factor = fabs(((double)mlx->x - WIDTH / 2) / (WIDTH / 2)); // distance from the center

        	// Weight the vertical more heavily to make the gradient focus vertically
        	//double blend_factor = vertical_factor * (0.0 - horizontal_factor);
			ray.direction = create_vect(mlx->x / 2, (mlx->y / 2), 0.0);
      		ray.color = gradient_color(ray_color(&ray));
      		mlx_put_pixel(mlx->img, mlx->x, mlx->y, ray.color);
			mlx->y++;
		}
		mlx->x++;
	}
	//int radius = 200;
//	draw_sphere(mlx, WIDTH / 2, HEIGHT / 2, radius);
	mlx_image_to_window(mlx->con, mlx->img, 0, 0);
	mlx_key_hook(mlx->con, manage_escape, mlx);
	mlx_loop(mlx->con);
	mlx_terminate(mlx->con);


	return (0);
}

int main()
{
	t_mlx	master;
	
	if (init_master(&master) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
