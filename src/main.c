/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/07 01:20:46 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

int	error_message(char *color, char *msg)
{
	printf(RED "\n\tError\n");
	printf("\t%s%s\n\n" NC, color, msg);
	return (1);
}

void	draw_cone(mlx_image_t *img, int32_t x, int32_t y, int32_t r, int32_t height, uint32_t color)
{
	int32_t base_width;
	int32_t	i;
	int32_t	j;

	for (i = 0; i <= height; i++)
	{
		base_width = (r * (height - i) / height);
		for (j = -base_width; j <= base_width; j++)
		{
			mlx_put_pixel(img, x + j, y + i, color);
		}
	}
}

void	start_mlx(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	uint32_t	color;

	mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	color = 0x0000FFFF;
    for (uint32_t x = 0; x < WIDTH; x++)
	{
        for (uint32_t y = 0; y < HEIGHT; y++)
		{
            mlx_put_pixel(img, x, y, 0xFFFFFFFF);
		}
	}
	draw_cone(img, WIDTH / 2, 250, 100, 300, 0x0000FFFF);
	draw_cone(img, WIDTH / 4, 200, 100, 100, 0xFF0000FF);
	draw_cone(img, WIDTH / 4 * 3, 150, 100, 500, 0x00FF00FF);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (read_file(argc, argv[1], &scene))
		return (EXIT_FAILURE);
	init_mlx(&scene);
	if (render_object(&scene))
		return (error_message(YEL, RENDER_ERROR));
	printf("acabado\n");
	mlx_key_hook(scene.mlx->con, &manage_escape, &scene);
	mlx_loop(scene.mlx->con);
	mlx_terminate(scene.mlx->con);
	exit(0);
	return (EXIT_SUCCESS);
}
