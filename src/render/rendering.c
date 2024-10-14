/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:59:36 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/15 00:19:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

/*ray_direction=lower_left_corner+u×horizontal+v×vertical−origin*/
#include <stdio.h>

// Assuming you've already defined your camera structure and vector operations (scalar_mult, add_vec3, etc.)

void test_get_pixel_direction(t_camera *cam, int img_w, int img_h) {
    // Test center pixel
    printf("Ray direction for center pixel: \n");
    t_vec3 center_ray = get_pixel_direction(cam, img_w / 2, img_h / 2);
    printf("Center Ray1: (%f, %f, %f)\n", center_ray.x, center_ray.y, center_ray.z);

   // Test top-left pixel
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
}

t_ray	hit_which_object(t_vec3 direction, t_vec3 origin, t_obj *obj)
{
	t_ray ray;

	if (obj->id == SP)
		ray = hit_sphere(direction, origin, obj->shape.sp);
	return (ray);
}

t_ray	intersect_objects(t_vec3 pxel_dir, t_vec3 cam_ori, t_obj *obj)
{
	t_ray		ray;
	t_ray		tmp_ray;
	//t_obj		*obj_head;

	//obj_head == obj;
	tmp_ray.hit = false;
	ray.distance = INFINITY;
	while (obj)
	{
		tmp_ray = hit_which_object(pxel_dir, cam_ori, obj);
		tmp_ray.object = obj;
		obj = obj->next;
		if (tmp_ray.hit == false)
			continue;
		tmp_ray.distance = euclidean_distance(cam_ori, tmp_ray.hit_point);
		if (tmp_ray.distance < ray.distance)
			ray = tmp_ray;
	}
	if (tmp_ray.hit == false)
		return(ray);
	ray.color = 0xFFFFFF;
	return (ray);
}

int	render_object(t_scene *scene)
{
	t_mlx		*mlx;
	t_camera	*cam;
	t_vec3		px_direction;
	t_ray		ray;

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
			ray = intersect_objects(px_direction, cam->origin, scene->obj);
			mlx_put_pixel(mlx->img, mlx->x, mlx->y, ray.color);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_image_to_window(mlx->con, mlx->img, 0, 0);
	return (0);
}
