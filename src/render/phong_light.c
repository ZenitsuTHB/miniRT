/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/18 00:05:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

uint32_t	gradient_color(t_rgb color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = (int)(color.red);//* 255.99);
	g = (int)(color.green);// * 255.99);
	b = (int)(color.blue);// * 255.99);
	return (r << 24 | g << 16 | b << 8 | 255);
}
t_rgb scalar_mult_color(t_rgb color, double scalar)
{
    return (t_rgb) {
        .red = fmin(color.red * scalar, 255),
        .green = fmin(color.green * scalar, 255),
        .blue = fmin(color.blue * scalar, 255)
    };
}

t_rgb add_colors(t_rgb c1, t_rgb c2)
{
    return (t_rgb) {
        .red = fmin(c1.red + c2.red, 255),
        .green = fmin(c1.green + c2.green, 255),
        .blue = fmin(c1.blue + c2.blue, 255)
    };
}

t_rgb    get_ambient_color(t_rgb base, t_scene *sc)
{
    t_rgb       color;
    t_rgb       ambient;

    ambient = dot_product(base, sc->light->color);
    color = scalar_mult_color(ambient, sc->ambient->bright);
    return(color);
}
/*/ Calculate the light direction (from hit point to light)
light_dir = unit_vec3(substract_vec3(light->position, ray->hit_point));
// View direction (from hit point to camera)
view_dir = unit_vec3(substract_vec3(cam->origin, ray->hit_point));
// Diffuse shading: Lambertian reflection
diffuse = fmax(0.0, dot_product(&light_dir, &ray->normal));  // ray->normal is the surface normal at hit point
// Specular shading: reflection of light about the normal
reflect_dir = reflect_vec(light_dir, ray->normal);  // Reflect the light vector around the normal
specular = pow(fmax(0.0, dot_product(&reflect_dir, &view_dir)), shininess);
*/
t_rgb    get_difuse_color(t_vec3 normal, t_vec3 hit_point, t_light *light)
{
    t_rgb   diffuse;
    t_vec3  lite_dir_v;
    double  dotLN;

    lite_dir_v =  unit_vec3(substract_vec3(light->pos, hit_point));
    dotLN = max(0, dot_product(&lite_dir_v, &normal));
    diffuse = 
    return (diffuse);
}

uint32_t    get_full_color(t_vec3 dir , t_ray ray, t_scene *sc)
{
    t_rgb amb;
    t_rgb full;
    t_rgb diffuse;
    t_rgb basecolor;
	
    basecolor = ray.object->shape.sp->color;
    amb =  get_ambient_color(basecolor, sc);
    diffuse = get_diffuse_color(ray.normal, ray.hit_point, sc->light);
    full = dot_product(basecolor, add_vec3(diffuse, amb)); 
    return (gradient_color(full));
}

uint32_t get_phong_effect(t_vec3 dir, t_ray ray, t_scene *scene)
{
    uint32_t    finished;
    t_rgb       tmp_color;

    tmp_color = ray.object->shape.sp->color;
    if (ray.object->id == SP)
		finished = get_full_color(dir, ray, scene);
	else if (ray.object->id == PL)
		finished = ray.object->shape.pl->color.gradient;
	else
		finished = 0xFF;
    return (finished);
}