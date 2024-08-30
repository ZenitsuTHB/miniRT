/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:45:16 by avolcy            #+#    #+#             */
/*   Updated: 2024/08/29 17:04:35 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/minirt.h>
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

void  manage_escape(mlx_key_data_t keydata, void *param)
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

	// Dibujar esfera

  mlx_key_hook(init.mlx_con, manage_escape ,init.mlx_con);
	radius = 50;
	draw_sphere(&init, WIDTH / 2, HEIGHT / 2, radius);

	// Meter la imagen en la pantalla
	
	mlx_image_to_window(init.mlx_con, init.mlx_img, 0, 0);

	// Esperar a que el usuario cierre la pantalla
	
	mlx_loop(init.mlx_con);
	

//static void mlx_render_images(mlx_t* mlx)
//void mlx_close_window(mlx_t* mlx)
//void mlx_delete_image(mlx_t* mlx, mlx_image_t* image)
//mlx_image_t* mlx_new_image(mlx_t* mlx, uint32_t width, uint32_t height)
//int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x, int32_t y)
//void mlx_set_instance_depth(mlx_instance_t* instance, int32_t zdepth)

int main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (check_args(argc, argv[1]) == -1)
		return (1);
	mlx.con = NULL;
	mlx.con = mlx_init(HEIGHT, WIDTH, "miniRT", true);
	if (mlx.con == NULL)
		return (1);

	mlx_loop(mlx.con);

	mlx_terminate(mlx.con);

	//printf("\n\nHALLO miniRT\n\n");
	return (EXIT_SUCCESS);
}
