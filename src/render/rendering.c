/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:59:36 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/15 20:08:24 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

#include <stdio.h>

void	hit_which_object(t_vec3 direction, t_vec3 origin, t_obj *obj, t_ray *ray)
{
	//t_ray	reset;

	//reset.hit = false;
	if (obj->id == SP)
		*ray = hit_sphere(direction, origin, obj->shape.sp);
	//else if (obj->id == PL)
	//	*ray = hit_plane(direction, origin, obj->shape.pl);
	//else
	//*ray = reset;
	//printf("ray hit info: %d\n", (int)ray->hit);
}
/*uint32_t	get_object_color(t_ray)
{
	
	
}*/

t_ray	intersect_objects(t_vec3 pxel_dir, t_vec3 cam_ori, t_obj *obj)
{
	t_ray		ray;
	t_ray		tmp_ray;
	t_obj		*obj_head;

	obj_head = obj;
	tmp_ray.hit = false;
	ray.hit = false;
	ray.distance = INFINITY;
	//printf("checking ray\n");
	while (obj)
	{
		//printf("Im in obj: %d\n", obj->id);
		ft_bzero(&tmp_ray, sizeof(t_ray));
		hit_which_object(pxel_dir, cam_ori, obj, &tmp_ray);
		tmp_ray.object = obj;
		obj = obj->next;
		if (tmp_ray.hit == false)
			continue;
		tmp_ray.distance = euclidean_distance(cam_ori, tmp_ray.hit_point);
		if (tmp_ray.distance < ray.distance)
			ray = tmp_ray;
	}
	if (ray.hit == false)
		return(ray);
	if (ray.object->id == SP)
		ray.color = ray.object->shape.sp->color.gradient;//get_object_color(ray);
	else if (ray.object->id == PL)
		ray.color = ray.object->shape.pl->color.gradient;//get_object_color(ray);
	else
		ray.color = 0xffFFffFF;
	return (ray);
}

/*#define BPP 1
void	my_put_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	int	thck[2];
	int	px[2];

	x *= BPP;
	y *= BPP;
	if (y < 0 || x < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	thck[0] = 0;
	while (thck[0] < BPP)
	{
		thck[1] = 0;
		while (thck[1] < BPP)
		{
			px[0] = x + thck[0];
			px[1] = y + thck[1];
			if (px[0] >= 0 && px[0] < WIDTH && px[1] >= 0 && px[1] < HEIGHT)
				mlx_put_pixel(img, x + thck[0], y + thck[1], color);
			thck[1]++;
		}
		thck[0]++;
	}
}*/
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
			//my_put_pixel(mlx->img, mlx->x, mlx->y, ray.color);
			if (!ray.hit)
				ray.color = 0xFF;
			mlx_put_pixel(mlx->img, mlx->x, mlx->y, ray.color);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_image_to_window(mlx->con, mlx->img, 0, 0);
	return (0);
}
