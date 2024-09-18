/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/15 19:27:15 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"
# include <../libs/MLX42/include/MLX42/MLX42.h>

void  generate_ray(t_camera *camera, t_ray *ray, int i, int j)
{
    double image_plane_width;
    double image_plane_height;

    ray->ratio = (double)WIDTH / (double)HEIGHT;
    // Calculate the image plane dimensions
    image_plane_height = 2 * tan(camera->fov / 2);
    image_plane_width = image_plane_height * ray->ratio;
    // Calculate normalized coordinates for the pixel
    double u = (i + 0.5) / WIDTH * 2 - 1;  // Horizontal pixel position in [-1, 1]
    double v = 1 - (j + 0.5) / HEIGHT * 2;  // Vertical pixel position in [-1, 1]
    // Scale by the image plane size
    double u_scaled = u * (image_plane_width / 2);
    double v_scaled = v * (image_plane_height / 2);
    // Calculate the ray direction
    direction = substract_vec3(add_vec3(add_vec3(cam->lower_left_corner,
                    multiply_vec3(cam->horizontal, s)),
                    multiply_vec3(cam->vertical, t)), origin);
    ray->direction = unit_vec3(camera->cam_dir + u_scaled * camera->right + 
                    v_scaled * camera->up);
    // Create and return the ray
    ray->origin = camera->pos;
}

int setting_camera(t_camera *cam)
{
  t_vec3  w;
  double  half_width;
  double  half_height;
  t_vec3  look_upward;

	cam->viewport_height = 2.0 * tan(deg_to_rad(cam->fov) / 2.0) * cam->focal_len;
	cam->viewport_width = cam->viewport_width * cam->ratio;
  half_width  = cam->viewport_width;
  half_height = cam->viewport_height;
  w = unit_vec3(scalar_mult(cam->cam_dir, -1));
  look_upward = (t_vec3){0, 1, 0};
  cam->right = unit_vec3(cross_product(&look_upward, &w));
  cam->up = cross_product(&w, &cam->right);
  cam->lower_left_corner = substract_vec3(cam->pos,
          add_vec3(scalar_mult(cam->right, half_width * cam->focal_len),
          add_vec3(scalar_mult(cam->up, half_height * cam->focal_len), 
          scalar_mult(w, cam->focal_len))));
  cam->horizontal = scalar_mult(cam->right, 2 * half_width * cam->focal_len);
  cam->vertical = scalar_mult(cam->up, 2 * half_height * cam->focal_len);
  return(0);
}
