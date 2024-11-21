/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/21 14:43:15 by avolcy           ###   ########.fr       */
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

	normalized[x_coord] = ((double)pixel_x / (IMG_W - 1));
	normalized[y_coord] = ((double)pixel_y / (IMG_H - 1));
	scaled[x_coord] = scalar_mult(cam->horizontal, normalized[x_coord]);
	scaled[y_coord] = scalar_mult(cam->vertical, normalized[y_coord]);
	added_scales = add_vec3(scaled[x_coord], scaled[y_coord]);
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
	double	half_width;
	double	half_height;
	t_vec3	look_upward;

	cam->cam_dir = unit_vec3(substract_vec3(cam->cam_dir, cam->origin));
	cam->vp_height = -0.4 * tan(deg_to_rad(cam->fov / 2)) * cam->focal_len;
	cam->vp_width = cam->vp_height * cam->ratio;
	half_width = -cam->vp_width;
	half_height = cam->vp_height;
	cam->neg_dir = unit_vec3(scalar_mult(cam->cam_dir, -1));
	look_upward = (t_vec3){0, 1, 0};
	cam->right = unit_vec3(cross_product(&look_upward, &cam->neg_dir));
	cam->up = cross_product(&cam->neg_dir, &cam->right);
	cam->l_l_corner = lower_left_corner(cam, half_width, half_height);
	cam->horizontal = scalar_mult(cam->right, 2 * half_width * cam->focal_len);
	cam->vertical = scalar_mult(cam->up, 2 * half_height * cam->focal_len);
	return (0);
}
