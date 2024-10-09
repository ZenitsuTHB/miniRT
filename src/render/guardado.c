// t_rgb	ray_color(int y, int height)
// {
// 	double	t;
// 	t_rgb	blue;
// 	t_rgb	white;
//
// 	t = (double)y / (height - 1);
// 	white = create_vec3(1.0, 1.0, 1.0);
// 	blue = create_vec3(0.5, 0.7, 1.0);
// 	return (add_vec3(scalar_mult(white, t), scalar_mult(blue, 1.0 - t)));
// }
//
// uint32_t	gradient_color(t_rgb color)
// {
// 	uint8_t	r;
// 	uint8_t	g;
// 	uint8_t	b;
//
// 	r = (int)(color.x * 255.99);
// 	g = (int)(color.y * 255.99);
// 	b = (int)(color.z * 255.99);
// 	return (r << 24 | g << 16 | b << 8 | 255); // Returning as RGBA format
// }
//
// void  render_pixie(mlx_image_t *img, int x, int y, t_scene *sc, bool hit, t_rgb color)
// {
// 	uint32_t final_color;
//
// 	(void)sc;
// 	if (hit == true)
// 	{
// 		final_color = gradient_color(color);
// 	}
// 	else
//   	{
// 		t_rgb bg_color =ray_color(y, HEIGHT);
// 		final_color = gradient_color(bg_color);
// 	}
//   mlx_put_pixel(img, x, y, final_color);
// }
//
// bool hit_objects(t_scene *scene, t_hit *hit, t_rgb *color)
// {
// 	t_objects *obj;
// 	t_sphere	*sp;
//
// 	obj = hit->object;
// 	sp = scene->spheres;
// 	while (obj)
// 	{
// 		if(obj->type == SP)
// 		{
// 			if(hit_sphere(scene->ray, sp, &hit->t))
// 			{
// 				*color = sp->color;
//     			return(true);
//   			}
// 		}
// 		// else if (obj->type == PL)
// 		// {
// 		// 	if (hit_plane(scene->ray, scene->planes, &hit->t))
// 		// 	{
// 		// 		*color = scene->planes->color;
// 		// 		return (true);
// 		// 	}
// 		// }
// 		obj = obj->next;
// 	}
//   return (false);
// }
//
// void  init_ray(t_camera *camera, t_ray *ray)
// {
//   	ray->ratio = (double)WIDTH / (double)HEIGHT;
// 	ray->img_pl_height = 2 * tan(camera->fov / 2);
// 	ray->img_pl_width = ray->img_pl_height * ray->ratio;
// }