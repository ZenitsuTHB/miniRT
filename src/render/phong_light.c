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

#include <math.h>
#include "../include/minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

    uint32_t	gradient_color(t_rgb color)
    {
        uint8_t	r;
        uint8_t	g;
        uint8_t	b;

        r = (int)(color.x);
        g = (int)(color.y);
        b = (int)(color.z);
        return (r << 24 | g << 16 | b << 8 | 255);
}
t_rgb scalar_mult_color(t_rgb color, double scalar)
{
    return (t_rgb) {
        .x = fmin(color.x * scalar, 255),
        .y = fmin(color.y * scalar, 255),
        .z = fmin(color.z * scalar, 255)
    };
}
double	maxim(double nb, double limit)
{
	if (nb > limit)
		return (nb);
	return (limit);
}
t_rgb add_colors(t_rgb c1, t_rgb c2)
{
    return (t_rgb) {
        .x = fmin(c1.x + c2.x, 255),
        .y = fmin(c1.y + c2.y, 255),
        .z = fmin(c1.z + c2.z, 255)
    };
}
/*1. Calculate the ambient lighting component
I_ambient = k_ambient * I_light rj : I_amb ​= 0.2×1.0=0.2
2. Apply ambient light to the object's color
final_color = base_color * I_ambient ej: fi_col = (1,0,0)×0.2=(0.2,0,0)
*/

t_rgb    get_ambient_color(t_rgb base, t_scene *sc)
{
    t_rgb       I_amb;

    I_amb = unit_vec3(multiply_vec3(base, sc->ambient->color));
    I_amb = scalar_mult(I_amb, sc->ambient->bright);
    return(I_amb);
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
t_rgb    get_difuse_color(t_rgb base, t_vec3 normal, t_vec3 hit_point, t_light *light)
{
    t_rgb   diffuse;
    t_vec3  lite_dir_v;
    double  dotLN;
    //printf("Normal Vector: (%f, %f, %f)\n", normal.x, normal.y, normal.z);
   // printf("Normal Vector: (%f, %f, %f)\n", hit_point.x, hit_point.y, hit_point.z);

    lite_dir_v =  unit_vec3(substract_vec3(light->pos, hit_point));
    dotLN = maxim(dot_product(&lite_dir_v, &normal), 0);
    diffuse =  multiply_vec3(base, light->color);
   // printf(" base              : (%f, %f, %f)\n", base.x, base.y, base.z);
  //  printf("Difuse light Vector: (%f, %f, %f)\n", diffuse.x, diffuse.y, diffuse.z);
    //printf("Light Direction Vector: (%f, %f, %f)\n", lite_dir_v.x, lite_dir_v.y, lite_dir_v.z);
    //printf("Dot Product (L · N): %f\n", dotLN);
    diffuse = scalar_mult(diffuse, dotLN);
   // printf("Difuse light Vector: (%f, %f, %f)\n", diffuse.x, diffuse.y, diffuse.z);
    diffuse = scalar_mult(base, light->bright);// * dotLN);
   // printf("Difuse light Vector: (%f, %f, %f)\n", diffuse.x, diffuse.y, diffuse.z);
    return (diffuse);
}

uint32_t    get_full_color(t_vec3 dir , t_ray ray, t_scene *sc)
{
    t_rgb amb;
    t_rgb full;
    t_rgb diffuse;
    t_rgb basecolor;

	(void)dir;
    basecolor = ray.object->shape.sp->color;
    amb =  get_ambient_color(basecolor, sc);
    diffuse = get_difuse_color(basecolor, ray.normal, ray.hit_point, sc->light);
    full = add_vec3(diffuse, amb);
    full = multiply_vec3(basecolor, full); 
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
		finished = ray.object->shape.pl->color.z;
	else
		finished = 0xFF;
    return (finished);
}