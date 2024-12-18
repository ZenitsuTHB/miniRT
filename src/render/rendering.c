/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:59:36 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/23 13:32:44 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>
#include <stdio.h>

void	hit_which_object(t_vec3 direction, t_vec3 origin, t_obj *obj,
		t_ray *ray)
{
	if (obj->id == SP)
		*ray = hit_sphere(direction, origin, obj->shape.sp);
	if (obj->id == PL)
		*ray = hit_plane(direction, origin, obj->shape.pl);
	if (obj->id == CY)
		*ray = hit_cylinder(direction, origin, obj->shape.cy);
	if (obj->id == CU)
		*ray = hit_cube(direction, origin, obj->shape.cu);
}

t_ray	intersect_obj(t_vec3 pxel_dir, t_vec3 ori, t_obj *obj, t_scene *scene)
{
	t_ray	ray;
	t_ray	tmp_ray;
	t_obj	*obj_head;

	obj_head = obj;
	tmp_ray.hit = false;
	ray.hit = false;
	ray.distance = INFINITY;
	while (obj)
	{
		ft_bzero(&tmp_ray, sizeof(t_ray));
		hit_which_object(pxel_dir, ori, obj, &tmp_ray);
		tmp_ray.object = obj;
		obj = obj->next;
		if (tmp_ray.hit == false)
			continue ;
		tmp_ray.distance = euclidean_distance(ori, tmp_ray.hit_point);
		if (tmp_ray.distance < ray.distance)
			ray = tmp_ray;
	}
	if (ray.hit == false)
		return (ray);
	ray.color = get_phong_effect(ray, scene, obj_head);
	return (ray);
}

static void	render_object_while(t_scene *scene, t_camera *cam)
{
	t_mlx	*mlx;
	t_ray	ray;
	t_vec3	px_direction;

	mlx = scene->mlx;
	mlx->x = 0;
	while (mlx->x < WIDTH)
	{
		mlx->y = 0;
		while (mlx->y < HEIGHT)
		{
			px_direction = get_pixel_direction(cam, mlx->x, mlx->y);
			ray = intersect_obj(px_direction, cam->origin, scene->obj, scene);
			if (!ray.hit)
				ray.color = 0xFF;
			mlx_put_pixel(mlx->img, mlx->x, mlx->y, ray.color);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_image_to_window(mlx->con, mlx->img, 0, 0);
}

int	render_object(t_scene *scene)
{
	t_camera	*cam;

	cam = scene->camera;
	setting_up_camera(cam);
	if (init_window(scene->mlx))
		return (error_message(YEL, ERROR_WIND));
	render_object_while(scene, cam);
	return (0);
}
