/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/24 00:05:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

t_vec3	get_pixel_direction(t_camera *cam, int pixel_x, int pixel_y)
{
	t_vec3	ray_dir;
	t_vec3	scaled[2];
	t_vec3	added_scales;
	t_vec3	px_point;
	double	normalized[2];

	normalized[X_COORD] = ((double)pixel_x / (IMG_W - 1));
	normalized[Y_COORD] = ((double)pixel_y / (IMG_H - 1));
	scaled[X_COORD] = scalar_mult(cam->horizontal, normalized[X_COORD]);
	scaled[Y_COORD] = scalar_mult(cam->vertical, normalized[Y_COORD]);
	added_scales = add_vec3(scaled[X_COORD], scaled[Y_COORD]);
	px_point = add_vec3(cam->l_l_corner, added_scales);
	ray_dir = substract_vec3(px_point, cam->origin);
	return (unit_vec3(ray_dir));
}

t_vec3	lower_left_corner(t_camera *cam, double half_W, double half_H)
{
	t_vec3	l_l_c;
	t_vec3	adding[5];

	adding[0] = scalar_mult(cam->neg_dir, cam->focal_len);
	adding[1] = scalar_mult(cam->up, half_H * cam->focal_len);
	adding[2] = scalar_mult(cam->right, half_W * cam->focal_len);
	adding[3] = add_vec3(adding[0], adding[1]);
	adding[4] = add_vec3(adding[3], adding[2]);
	l_l_c = substract_vec3(cam->origin, adding[4]);
	return (l_l_c);
}

int	setting_up_camera(t_camera *cam)
{
	t_vec3	dir;
	double	half_width;
	double	half_height;
	t_vec3	look_upward;

	dir = unit_vec3(cam->cam_dir);
	cam->vp_height = -tan(deg_to_rad(cam->fov / 2)) * cam->focal_len;
	cam->vp_width = cam->vp_height * cam->ratio;
	half_width = -cam->vp_width / 2;
	half_height = cam->vp_height / 2;
	cam->neg_dir = unit_vec3(scalar_mult(dir, -1));
	look_upward = (t_vec3){0, 1, 0};
	cam->right = unit_vec3(cross_product(&look_upward, &cam->neg_dir));
	cam->up = cross_product(&cam->neg_dir, &cam->right);
	cam->l_l_corner = lower_left_corner(cam, half_width, half_height);
	cam->horizontal = scalar_mult(cam->right, 2 * half_width * cam->focal_len);
	cam->vertical = scalar_mult(cam->up, 2 * half_height * cam->focal_len);
	return (0);
}
