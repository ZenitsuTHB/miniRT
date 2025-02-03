/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_use.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:01:11 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/24 18:35:51 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include "../include/struct.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

int	init_mlx(t_scene *scene)
{
	scene->mlx = malloc(sizeof(t_mlx));
	if (!scene->mlx)
		return (error_message(RED, MALLOC_ERROR));
	return (0);
}

int	init_window(t_mlx *mlx)
{
	mlx->con = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	if (mlx->con == NULL)
		return (1);
	mlx->img = mlx_new_image(mlx->con, WIDTH, HEIGHT);
	if (mlx->img == NULL)
		return (1);
	return (0);
}

void	manage_escape(mlx_key_data_t keydata, void *param)
{
	t_mlx	*mlx;
	t_scene	*scene;

	scene = (t_scene *)param;
	mlx = scene->mlx;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		printf("Escape key pressed. Exiting...\n");
		mlx_delete_image(mlx->con, mlx->img);
		mlx_close_window((mlx->con));
		mlx_terminate(mlx->con);
		exit(0);
	}
	else
	{
		printf("No functionality for : %d yet !\n", keydata.key);
	}
}
