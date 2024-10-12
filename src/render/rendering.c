/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:59:36 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/12 19:36:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

/*ray_direction=lower_left_corner+u×horizontal+v×vertical−origin*/
#include <stdio.h>

// Assuming you've already defined your camera structure and vector operations (scalar_mult, add_vec3, etc.)

void test_get_pixel_direction(t_camera *cam, int img_w, int img_h) {
    // Test center pixel
    printf("Camera origin : [%lf]--[%lf]--[%lf]\n", cam->origin.x, cam->origin.y, cam->origin.z);
    printf("Ray direction for center pixel: [%d]-----[%d]\n", img_w, img_h);
    t_vec3 center_ray = get_pixel_direction(cam, img_w / 2, img_h / 2);
    printf("Center Ray: (%f, %f, %f)\n", center_ray.x, center_ray.y, center_ray.z);

   /* // Test top-left pixel
    printf("Ray direction for top-left pixel:\n");
    t_vec3 top_left_ray = get_pixel_direction(cam, 0, 0);
    printf("Top-left Ray: (%f, %f, %f)\n", top_left_ray.x, top_left_ray.y, top_left_ray.z);

    // Test top-right pixel
    printf("Ray direction for top-right pixel:\n");
    t_vec3 top_right_ray = get_pixel_direction(cam, img_w - 1, 0);
    printf("Top-right Ray: (%f, %f, %f)\n", top_right_ray.x, top_right_ray.y, top_right_ray.z);

    // Test bottom-left pixel
    printf("Ray direction for bottom-left pixel:\n");
    t_vec3 bottom_left_ray = get_pixel_direction(cam, 0, img_h - 1);
    printf("Bottom-left Ray: (%f, %f, %f)\n", bottom_left_ray.x, bottom_left_ray.y, bottom_left_ray.z);

    // Test bottom-right pixel
    printf("Ray direction for bottom-right pixel:\n");
    t_vec3 bottom_right_ray = get_pixel_direction(cam, img_w - 1, img_h - 1);
    printf("Bottom-right Ray: (%f, %f, %f)\n", bottom_right_ray.x, bottom_right_ray.y, bottom_right_ray.z);
*/
}

t_vec3	get_pixel_direction(t_camera *cam, int pixel_x, int pixel_y)
{
	t_vec3	ray_dir;
	t_vec3	x_scaled;
	t_vec3	y_scaled;
	t_vec3	added_scales;
	double	normalized[2];

	normalized[x_coord] = (double)pixel_x / (IMG_W - 1);
	normalized[y_coord] = (double)pixel_y / (IMG_H - 1);
	//printf("\nnormali x and y %lf-- %lf\n" ,normalized[x_coord], normalized[y_coord]);
	x_scaled = scalar_mult(cam->horizontal, normalized[0]);
	y_scaled = scalar_mult(cam->vertical, normalized[1]);
	//printf("\nhorizontal %lf--%lf--%lf\n" ,cam->horizontal.x,cam->horizontal.y,cam->horizontal.z);
	//printf("\n xscaled and yscaled %lf--%lf--%lf\n%lf--%lf--%lf\n" ,x_scaled.x,x_scaled.y,x_scaled.z,y_scaled.x,y_scaled.y,y_scaled.z);
	added_scales = add_vec3(x_scaled, y_scaled);
	//printf("\n xscaled and yscaled %lf--%lf--%lf\n" ,added_scales.x,added_scales.y,added_scales.z);
	ray_dir = substract_vec3(add_vec3(cam->l_l_corner, added_scales), cam->origin);	
	return(unit_vec3(ray_dir));
} 

int	render_object(t_scene *scene)
{
	t_mlx		*mlx;
	t_camera	*cam;
	t_vec3		px_direction;

	cam = scene->camera;
	setting_up_camera(cam);
	if (init_window(scene->mlx))
		return (error_message(YEL, ERROR_WIND));
	mlx = scene->mlx;
	mlx->x = 0;
	while (mlx->x < WIDTH)
	{
		mlx->y = 0;
		while (mlx->y < HEIGHT)
		{
			px_direction = get_pixel_direction(cam, mlx->x, mlx->y);
			//test_get_pixel_direction(cam, IMG_W, IMG_H);
			(void)px_direction;
			mlx_put_pixel(mlx->img, mlx->x, mlx->y, 0x0);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_image_to_window(mlx->con, mlx->img, 0, 0);
	return (0);
}
