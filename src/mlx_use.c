/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_use.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:01:11 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/13 20:21:52 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "minirt.h"
# include <../libs/MLX42/include/MLX42/MLX42.h>


int	init_window(t_mlx *mlx)
{
	
	mlx->con = mlx_init(HEIGHT, WIDTH, "miniRT", false);
	if (mlx->con == NULL)
		return (1);
	//mlx->img =  mlx_new_image(mlx->con, WIDTH, HEIGHT);
	//if (mlx->img == NULL)
	//	return (1);
	return (0);
}

void	manage_escape(mlx_key_data_t keydata, void *param)
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
