/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainold.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:45:16 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/02 19:06:10 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/minirt.h>
#include <math.h>
#include <stdio.h>
void draw_sphere(t_mlx *mlx, int cx, int cy, int radius)
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
                mlx_put_pixel(mlx->img->ptr, cx + x, cy + y, pixel_color);
            }
        }
    }
}
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

int main()
{
    t_mlx mlx;
    int radius = 50;

    // Initialize MiniLibX
    mlx.con = mlx_init(WIDTH, HEIGHT, "miniRT", true);
    if (mlx.con == NULL)
    {
        fprintf(stderr, "Failed to initialize MiniLibX\n");
        return EXIT_FAILURE;
    }

    // Allocate memory for the t_img structure
    mlx.img = malloc(sizeof(t_img));
    if (mlx.img == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for t_img\n");
        mlx_terminate(mlx.con);
        return EXIT_FAILURE;
    }

    // Create a new image and assign it to the t_img structure
    mlx.img->ptr = mlx_new_image(mlx.con, WIDTH, HEIGHT);
    if (!mlx.img->ptr)
    {
        fprintf(stderr, "Failed to create image\n");
        free(mlx.img);
        mlx_terminate(mlx.con);
        return EXIT_FAILURE;
    }

    // Set the t_img fields based on mlx_image_t properties
    mlx_image_t *mlx_image = (mlx_image_t *)mlx.img->ptr; // Cast to mlx_image_t *
    mlx.img->addr = (char *)mlx_image->pixels;
    mlx.img->bits_per_pixel = 32; // Assuming 32 bits (4 bytes) per pixel (RGBA)
    mlx.img->line_length = mlx_image->width * 4; // 4 bytes per pixel
    mlx.img->endian = 1; // Adjust this value based on your needs

    // Draw the sphere
    draw_sphere(&mlx, WIDTH / 2, HEIGHT / 2, radius);

    // Display the image
    if (mlx_image_to_window(mlx.con, (mlx_image_t *)mlx.img->ptr, 0, 0) < 0)
    {
        fprintf(stderr, "Failed to put image to window\n");
        free(mlx.img);
        mlx_terminate(mlx.con);
        return EXIT_FAILURE;
    }

    // Register the key hook for escape key
    mlx_key_hook(mlx.con, manage_escape, mlx.con);

    // Enter the MiniLibX event loop
    mlx_loop(mlx.con);

    // Cleanup
    mlx_delete_image(mlx.con, (mlx_image_t *)mlx.img->ptr);
    free(mlx.img);
    mlx_terminate(mlx.con);

    return EXIT_SUCCESS;
}
// void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char	*dst;
//
// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }
//
// void  plan(t_mlx *mlx)
// {
//   int color = 0;
//   mlx->y = 0;
//   while (mlx->y < HEIGHT)
//   {
//     mlx->x = 0;
//     while (mlx->x < WIDTH)
//     {
//       if (mlx->y > HEIGHT / 2)
//         color = 0xFF0A;
//       else 
//         color = 0x00FF0A;
//       my_mlx_pixel_put(mlx->img, mlx->x++, mlx->y, color);
//     }
//     mlx->y++;
//   }
//   mlx_image_to_window(mlx->con, mlx->img->ptr, 0, 0);
// }
//
// void  manage_escape(mlx_key_data_t keydata, void *param)
// {
//
//   if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
//     {
//         printf("Escape key pressed. Exiting...\n");
//         mlx_close_window((mlx_t*)param);
//     }
//     else
//     {
//         printf("Key pressed: %d\n", keydata.key);
//     }
// }
//
// int	main()
// {
//   t_mlx	mlx;
//
// 	mlx.con = NULL;
// 	mlx.con = mlx_init(HEIGHT, WIDTH, "miniRT", true);
// 	if (mlx.con == NULL)
// 		return (1);
//
//   // Inicializar
//
//   (mlx_image_t*)mlx.img->ptr = mlx_new_image(mlx.con, 600, 400);
//   if (!mlx.img)
//     return (1);
//
//   plan(&mlx);
//
//    if (mlx_image_to_window(mlx.con, mlx.img->ptr, 0, 0) < 0)
//     return 1;
//
//   mlx_key_hook(mlx.con, manage_escape ,mlx.con);
//   mlx_loop(mlx.con);
//   // mlx_delete_image(mlx.con, mlx.img);
// 	mlx_terminate(mlx.con);
//
// 	//printf("\n\nHALLO miniRT\n\n");
// 	return (EXIT_SUCCESS);
// }
