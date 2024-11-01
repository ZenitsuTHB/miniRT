/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/01 02:56:29 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../include/minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

t_rgb scalar_mult_color(t_rgb color, double scalar)
{
    return (t_rgb) {
        .x = fmin(color.x * scalar, 255),
        .y = fmin(color.y * scalar, 255),
        .z = fmin(color.z * scalar, 255)
    };
}

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

double	maxim(double nb, double limit)
{
	if (nb > limit)
		return (nb);
	return (limit);
}
t_vec3 reflect_vec(t_vec3 light_dir, t_vec3 normal)
{
    double teta_angle;
    t_vec3 reflection;
    t_vec3 scalar_reflect;

    teta_angle = dot_product(&normal, &light_dir) * 2;
    scalar_reflect = scalar_mult(normal, teta_angle);
    reflection = substract_vec3(scalar_reflect, light_dir);
    return (reflection);
}
//reflecdirection = light_dir - 2 * (normal * light_dir) * normal;
// Final specular color (light color * intensity * specular factor)
t_rgb get_specular_color(t_obj *obj, t_light *light, t_vec3 point, t_camera *cam)
{
    double spec;
    t_vec3 normal;
    t_vec3 light_dir;
    t_vec3 reflect_dir;
    t_vec3 view_dir;
    
    spec = 0.0;
    normal = (t_vec3){0, 0, 0};
    normal = obj->normal;
    view_dir = unit_vec3(substract_vec3(point, cam->origin));
    light_dir = unit_vec3(substract_vec3(point, light->pos));
    reflect_dir = reflect_vec(light_dir, normal);
    spec = pow(fmax(dot_product(&view_dir, &reflect_dir), 0.0), 255.9);
    return scalar_mult(light->color, light->bright * spec);
}

//AmbL = basecolor * Iamb;
t_rgb    get_ambient_color(t_rgb base, t_scene *sc)
{
    t_rgb       I_amb;
    // t_rgb       lights;

    //lights = add_vec3(base, sc->ambient->color);
    //lights = multiply_vec3(base, sc->ambient->color);
    I_amb = scalar_mult(base, sc->ambient->bright);
    return(I_amb);
}

//diffuse = light_intensity * COSINE tEtA(angle(normal, lightdir)) * obj_color;
t_vec3 get_diffuse_color(t_obj *obj, t_light *light, t_vec3 point)
{
    double dotLN;
    t_vec3 diffuse;
    t_vec3 light_dir;

    light_dir = unit_vec3(substract_vec3(light->pos, point));
    dotLN = fmax(0, dot_product(&obj->normal, &light_dir));
    diffuse = scalar_mult(obj->color, light->bright * dotLN);
    return (diffuse);
}
void   get_normal_and_color(t_vec3 hitpoint, t_obj **object)
{
    if  ((*object)->id == SP)
    {
        (*object)->color = (*object)->shape.sp->color;
        (*object)->normal = unit_vec3(substract_vec3(hitpoint, 
        (*object)->shape.sp->center));
       
    }
    else if ((*object)->id == PL)
    {
        (*object)->color = (*object)->shape.pl->color;
        (*object)->normal = (*object)->shape.pl->normal;
    } 
}

t_rgb clamp_color(t_rgb color)
{
    color.x = fmin(255, fmax(0, color.x));
    color.y = fmin(255, fmax(0, color.y));
    color.z = fmin(255, fmax(0, color.z));
    return (color);
}
t_rgb accumulation_color(t_rgb constant, t_rgb temp)
{
    t_rgb saved;

    saved = add_vec3(constant, temp);
    return (saved);
}

uint32_t    get_full_color(t_ray ray, t_scene *sc, t_light **light)
{
   t_rgb full;
   t_rgb I_amb;
   t_rgb diffuse;
   t_rgb specular;
   t_rgb finished;
   t_light *lighter;
    
    lighter = *light;
    finished = (t_rgb){0,0,0};
    get_normal_and_color(ray.hit_point, &ray.object);
    while (lighter)
    {
        I_amb =  get_ambient_color(ray.object->color, sc);
	    diffuse = get_diffuse_color(ray.object, lighter, ray.hit_point);
        specular = get_specular_color(ray.object, lighter, ray.hit_point, sc->camera);
        //is_shadowed(); full = I_amb;
        full = add_vec3(add_vec3(specular, diffuse), I_amb);
        finished = accumulation_color(finished, full);
        full = (t_rgb){0,0,0};
        lighter = lighter->next;
    }
    return (gradient_color(clamp_color(finished)));
}

uint32_t get_phong_effect(t_ray ray, t_scene *scene)
{
    t_light     **light;
    uint32_t    phong_color;

    light = &scene->light;
    phong_color = get_full_color(ray, scene, light);
    return (phong_color);
}


