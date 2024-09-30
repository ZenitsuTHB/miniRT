/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:45:16 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/30 18:24:01 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int	error_message(char *color, char *msg)
{
	printf(RED"\n\tError\n");
	printf("\t%s%s\n\n"NC, color, msg);
	return (-1);
}

int	ft_mlx_init(t_scene *scene)
{
	mlx_t		*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	if (!mlx)
		return (1);
	scene->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!scene->img)
		return (1);
	mlx_image_to_window(mlx, scene->img, 0, 0);
	draw_scene(scene);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (read_file(argc, argv[1], &scene))
		return (free_scene(&scene), EXIT_FAILURE);
	if (ft_mlx_init(&scene))
		return (free_scene(&scene), EXIT_FAILURE);
	print_scene(scene);
	free_scene(&scene);
	return (EXIT_SUCCESS);
}
