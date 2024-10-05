/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/05 11:53:25 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

int error_message(char *color, char *msg)
{
	printf(RED "\n\tError\n");
	printf("\t%s%s\n\n" NC, color, msg);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_scene scene;

	if (read_file(argc, argv[1], &scene))
		return (EXIT_FAILURE);
		
		//return (free_scene(&scene), EXIT_FAILURE);
	
	/*
	if (render_object(&scene))
		return (error_message(YEL, RENDER_ERROR));
	mlx_key_hook(scene.mlx->con, &manage_escape, scene.mlx);
	mlx_loop(scene.mlx->con);
	mlx_terminate(scene.mlx->con);
	*/
	free_scene(&scene);
	return (EXIT_SUCCESS);
}
