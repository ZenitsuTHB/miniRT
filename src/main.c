/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:45:16 by avolcy            #+#    #+#             */
/*   Updated: 2024/08/29 20:56:14 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"
#include <math.h>

void draw_sphere(t_win *mlx, int cx, int cy, int radius)
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
                uint32_t pixel_color = (brightness << 16) | (brightness << 8) | brightness;
                mlx_put_pixel(mlx->mlx_img, cx + x, cy + y, pixel_color);
            }
        }
    }
}

void my_key_function(mlx_key_data_t keydata, void* param)
{
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
        printf("Escape key pressed. Exiting...\n");
        mlx_close_window((mlx_t*)param);
    }
    else
    {
        printf("Key pressed: %d\n", keydata.key);
    }
}

//	void mlx_mouse_hook(mlx_t* mlx, mlx_mousefunc func, void* param)
int	main()
{
	t_win	init;
	int		radius;

	// Inicializar

	init.mlx_con = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	if (!init.mlx_con)
		return (1);

	// Crear imagen
	
	init.mlx_img = mlx_new_image(init.mlx_con, WIDTH, HEIGHT);
	if (!init.mlx_img)
		return (1);


	radius = 50;
	draw_sphere(&init, WIDTH / 2, HEIGHT / 2, radius);

	// Meter la imagen en la pantalla
	
	mlx_key_hook(init.mlx_con, my_key_function, init.mlx_con);
//	mlx_mouse_hook(init.mlx_con, mouse_event, init.mlx);
	mlx_image_to_window(init.mlx_con, init.mlx_img, 0, 0);

	// Esperar a que el usuario cierre la pantalla
	
	mlx_loop(init.mlx_con);

	mlx_terminate(init.mlx_con);
	return (0);	
}
