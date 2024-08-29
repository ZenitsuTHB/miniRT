/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:45:16 by avolcy            #+#    #+#             */
/*   Updated: 2024/08/29 20:59:58 by avolcy           ###   ########.fr       */
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
int			error_message(char *color, char *msg)
{
	printf(RED"\n\tError\n");
	printf("\t%s%s\n\n"NC, color, msg);
	return (-1);
}

int check_args(int argc, char *scene)
{
	int i;

	i = 0;
	if (argc != 2)
		return (error_message(YEL, ERROR_ARG));
	//check the extensions is correct 
	printf("ARGUMENT : %s\n", scene);
	if (scene[0] == '.')
		i++;
	while (scene[i] && scene[i] != '.')
		i++;
	printf("extension : %s\n", &scene[i]);

	printf("len of file %ld\n", ft_strlen(&scene[i]));
	printf("return value of strcpim  %d\n", ft_strncmp(&scene[i], ".rt", 4));
	if (ft_strncmp(&scene[i], ".rt", 4) != 0 || ft_strlen(scene) <= 3)
	{
		if (ft_strlen(scene) <= 3)
			return (error_message(YEL, "Only extension ! file name missed."));
		return (error_message(YEL, ERROR_EXTENSION));
	}


	//check for file permision, Open file and 
	//check if the file format meet the subject requirements
	//open, close, read, write,
	//printf, malloc, free, perror,
	//strerror, exit
	
	return 0;
}

//bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param)
//static void mlx_render_images(mlx_t* mlx)
//void mlx_close_window(mlx_t* mlx)
//void mlx_delete_image(mlx_t* mlx, mlx_image_t* image)
//mlx_image_t* mlx_new_image(mlx_t* mlx, uint32_t width, uint32_t height)
//int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x, int32_t y)
//void mlx_set_instance_depth(mlx_instance_t* instance, int32_t zdepth)

int main(int argc, char *argv[])
{
	t_win init;

	if (check_args(argc, argv[1]) == -1)
		return (1);
	init.mlx_connection = NULL;
	init.mlx_connection = mlx_init(HEIGHT, WIDTH, "miniRT", true);
	if (init.mlx_connection == NULL)
		return (1);

	mlx_loop(init.mlx_connection);

	mlx_terminate(init.mlx_connection);

	//printf("\n\nHALLO miniRT\n\n");
	return (EXIT_SUCCESS);
}
