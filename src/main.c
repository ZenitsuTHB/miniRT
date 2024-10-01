/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:45:16 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/01 13:33:12 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int error_message(char *color, char *msg)
{
	printf(RED "\n\tError\n");
	ft_putstr_fd("\t", 2);
	ft_putstr_fd(color, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n\n" NC, 2);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_scene scene;

	if (read_file(argc, argv[1], &scene))
		return (free_scene(&scene), EXIT_FAILURE);
	print_scene(scene);
	if (render_object(&scene))
		return (error_message(YEL, RENDER_ERROR));
	mlx_key_hook(scene.mlx->con, &manage_escape, scene.mlx);
	mlx_loop(scene.mlx->con);
	mlx_terminate(scene.mlx->con);
	free_scene(&scene);
	return (EXIT_SUCCESS);
}
