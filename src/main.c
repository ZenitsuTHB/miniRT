/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/04 12:09:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

# include <../libs/MLX42/include/MLX42/MLX42.h>

uint32_t gradient_color(int y, int height)
{
    // Calculate the interpolation factor (0 at the top, 1 at the bottom)
    float factor = (float)y / height;

    // Interpolating between blue (0x0000FF) and white (0xFFFFFF)
    uint8_t r = (uint8_t)(255 * factor);   // Red component increases with factor
    uint8_t g = (uint8_t)(255 * factor);   // Green component increases with factor
    uint8_t b = 255;                       // Blue component stays 255

    return (r << 24 | g << 16 | b << 8 | 255); // Returning as RGBA format
}

void manage_escape(mlx_key_data_t keydata, void *param)
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

int			error_message(char *color, char *msg)
{
	printf(RED"\n\tError\n");
	printf("\t%s%s\n\n"NC, color, msg);
	return (-1);
}

int	init_window(t_mlx *mlx)
{
	mlx_image_t *img;

  
	img = mlx->img->ptr;
	mlx->con = mlx_init(HEIGHT, WIDTH, "miniRT", false);
	if (mlx->con == NULL)
		return (1);
	img =  mlx_new_image(mlx->con, WIDTH, HEIGHT);
	if (img == NULL)
		return (1);
	mlx->x = 0;
	while (mlx->x < WIDTH)
	{
    mlx->y = 0;
		while (mlx->y < HEIGHT)
		{
      uint32_t color = gradient_color(mlx->y, HEIGHT);
      mlx_put_pixel(img, mlx->x, mlx->y, color);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_image_to_window(mlx->con, img, 0, 0);
	mlx_key_hook(mlx->con, manage_escape, mlx);
	mlx_loop(mlx->con);
	mlx_terminate(mlx->con);
	return (0);
}

int	init_master(t_mlx *mlx)
{
	if (init_window(mlx))
		return (error_message( YEL ,ERROR_WIND));
	
	return (0);
}

int main()
{
	t_mlx	master;
	
	if (init_master(&master) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
