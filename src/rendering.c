/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:59:36 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/15 21:47:24 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

t_rgb	ray_color(int y, int height)
{
	double	t;
	t_rgb	blue;
	t_rgb	white;

	t = (double)y / (height - 1);
	white = create_vec3(1.0, 1.0, 1.0);
	blue = create_vec3(0.5, 0.7, 1.0);
	return (add_vec3(scalar_mult(white, t), scalar_mult(blue, 1.0 - t)));
}

uint32_t	gradient_color(t_rgb color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = (int)(color.x * 255.99);
	g = (int)(color.y * 255.99);
	b = (int)(color.z * 255.99);
	return (r << 24 | g << 16 | b << 8 | 255); // Returning as RGBA format
}

void  render_pixie(mlx_image_t *img, int x, int y, t_scene *sc)
{
	t_rgb color;
  uint32_t final_color;

  (void)sc;
  color = ray_color(y, HEIGHT);
  final_color = gradient_color(color);
  mlx_put_pixel(img, x, y, final_color);
}

bool hit_objects(t_scene *scene, t_hit *hit)
{
  if(hit_sphere(scene->ray, scene->spheres, &hit->t))
  {
    printf("RAY HIT SPHERE  \n");
    return(true);
  }
  return (false);
}

void  init_ray(t_camera *camera, t_ray *ray)
{
  ray->ratio = (double)WIDTH / (double)HEIGHT;
	ray->img_pl_height = 2 * tan(camera->fov / 2);
	ray->img_pl_width = ray->img_pl_height * ray->ratio;
}

int	render_object(t_scene *scene)
{
	t_mlx	*mlx;
  
  init_ray(scene->camera, scene->ray);
	if (setting_camera(scene->camera))
		return (error_message(YEL, "Failed to setting up camera."));
  if (init_window(scene->mlx))
		return (error_message(YEL, ERROR_WIND));
	mlx = scene->mlx;
	mlx->x = 0;
	while (mlx->x < WIDTH)
	{
		mlx->y = 0;
		while (mlx->y < HEIGHT)
		{
			generate_ray(scene->camera, scene->ray, mlx->x, mlx->y);
      hit_objects(scene, scene->hit);
      render_pixie(mlx->img, mlx->x, mlx->y, scene);
			mlx->y++;
		}
		mlx->x++;
	}
	mlx_image_to_window(mlx->con, mlx->img, 0, 0);
	return (0);
}
