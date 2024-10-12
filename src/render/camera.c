/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/12 19:45:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

// u is Horizontal pixel position in [-1, 1]
// v is Vertical pixel position in [-1,1]
/* void  generate_ray(t_camera *camera, t_ray *ray, int i, int j)
{
	double  u_scaled;
	double  v_scaled;
	double  u;
	double  v;

	u = ((i + 0.5) / WIDTH) * 2 - 1;
	v = 1 - ((j + 0.5) / HEIGHT) * 2;
	u_scaled = u * (ray->img_pl_width / 2);
	v_scaled = v * (ray->img_pl_height / 2);
	ray->direction = unit_vec3(add_vec3(camera->cam_dir,
				add_vec3(scalar_mult(camera->right, u_scaled),
					scalar_mult(camera->up, v_scaled))));
	ray->origin = camera->pos;
} */

t_vec3	lower_left_corner(t_camera *cam, double half_W, double half_H)
{
	t_vec3	l_l_c;
	t_vec3	adding[5];

	adding[0] = scalar_mult(cam->neg_dir, cam->focal_len);
	adding[1] = scalar_mult(cam->up, half_H *cam->focal_len);
	adding[2] = scalar_mult(cam->right, half_W *cam->focal_len);
	adding[3] = add_vec3(adding[0], adding[1]);
	adding[4] = add_vec3(adding[3], adding[2]);
	l_l_c = substract_vec3(cam->origin, adding[4]);	
	return (l_l_c);
}
void init_operation_vars(t_camera *cam)
{
	printf("fov--[%d]\noriginX-[%lf]-originY[%lf]-originZ[%lf]\ndirX-[%lf]-dirY[%lf]-dirZ[%lf]", cam->fov, cam->origin.x, cam->origin.y, cam->origin.z, 
	cam->cam_dir.x, cam->cam_dir.y, cam->cam_dir.z);
	/*fov;
	origin;
	cam_dir;
	ratio;
	focal_len;
	vp_width;
	vp_height;
	up;
	right;
	neg_dir;
	vertical;
	horizontal;
	l_l_corner;*/
	
}

int	setting_up_camera(t_camera *cam)
{
	double	half_width;
	double	half_height;
	t_vec3	look_upward;
	
	init_operation_vars(cam);
	cam->focal_len = 1.0;
	cam->ratio = (double)WIDTH / (double)HEIGHT;
	cam->vp_height = 2.0 * tan(deg_to_rad(cam->fov) / 2.0)
		* cam->focal_len;
	cam->vp_width = cam->vp_height * cam->ratio;
	half_width = cam->vp_width;
	half_height = cam->vp_height;
	cam->neg_dir = unit_vec3(scalar_mult(cam->cam_dir, -1));
	printf("\n negativo de la direction %lf--%lf--%lf\n" ,cam->neg_dir.x, cam->neg_dir.y,cam->neg_dir.z);

	look_upward = (t_vec3){0, 1, 0};
	cam->right = unit_vec3(cross_product(&look_upward, &cam->neg_dir));
	printf("\n right %lf--%lf--%lf\n" ,cam->right.x, cam->right.y,cam->right.z);
	
	cam->up = cross_product(&cam->neg_dir, &cam->right);
	cam->l_l_corner = lower_left_corner(cam, half_width, half_height);
	cam->horizontal = scalar_mult(cam->right, 2 * half_width * cam->focal_len);
	printf("\nhorizontal %lf--%lf--%lf\n" ,cam->horizontal.x,cam->horizontal.y,cam->horizontal.z);
	cam->vertical = scalar_mult(cam->up, 2 * half_height * cam->focal_len);
	return (0);
}
