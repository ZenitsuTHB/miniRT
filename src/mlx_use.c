/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_use.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:01:11 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/09 00:51:38 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struct.h"
#include "../include/minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

int	init_mlx(t_scene *scene)
{
	ft_bzero(scene, sizeof(t_scene));
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
  t_scene *scene;

  scene = (t_scene *)param;

	mlx = scene->mlx;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		printf("Escape key pressed. Exiting...\n");
		mlx_delete_image(mlx->con, mlx->img);
		mlx_close_window((mlx->con));
		mlx_terminate(mlx->con);
		// Cleanning function TODO
		exit(0);
	}
	else
	{
		printf("Key pressed: %d\n", keydata.key);
	}
}
