/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/02 19:49:46 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

# include <../libs/MLX42/include/MLX42/MLX42.h>
#define ERROR_WIND "Can't initialize Window !"

void manage_escape(mlx_key_data_t keydata, void *param)
{
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
        printf("Escape key pressed. Exiting...\n");

        mlx_close_window((mlx_t *)param);
    }
    else
    {
        printf("Key pressed: %d\n", keydata.key);
    }
}

int			error_message(char *color, char *msg)
{
	printf(RED"\n\tError\n");
	printf("\t%s%s\n\n"NC, color, msg);
	return (-1);
}

int	init_window(t_mlx *mlx)
{
	mlx->con = mlx_init(HEIGHT, WIDTH, "miniRT", true);
	if (mlx->con == NULL)
		return (1);
	mlx_key_hook(mlx->con, manage_escape, mlx->con);
	mlx_loop(mlx->con);
	return (0);
}

int	init_master(t_ray *master)
{
	//master->mlx = NULL;
	
	if (init_window(&master->mlx))
		return (error_message( YEL ,ERROR_WIND));
	return (0);
}

int main()
{
	t_ray	master;
	
	if (init_master(&master) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
