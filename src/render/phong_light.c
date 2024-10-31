/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/29 19:19:53 by avolcy           ###   ########.fr       */
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
    spec = dot_product(&normal, &light_dir) * 2;
    reflect_dir = scalar_mult(normal, spec);
    //printf("this is light dir (%lf, %lf, %lf)\n", light_dir.x, light_dir.y, light_dir.z);
    //printf("this is reflect_dir (%lf, %lf, %lf)\n", );
    reflect_dir = substract_vec3(reflect_dir, light_dir);
    spec = 0.0;
    spec = pow(fmax(dot_product(&view_dir, &reflect_dir), 0.0), 255.9);
    return scalar_mult(light->color, light->bright * spec);
}

t_rgb    get_ambient_color(t_rgb base, t_scene *sc)
{
    t_rgb       I_amb;
    // t_rgb       lights;

    //lights = add_vec3(base, sc->ambient->color);
    //lights = multiply_vec3(base, sc->ambient->color);
    I_amb = scalar_mult(base, sc->ambient->bright);
    return(I_amb);
}

t_vec3 get_diffuse_color(t_obj *obj, t_light *light, t_vec3 point)
{
    double dotLN;
    t_vec3 diffuse;
    t_vec3 light_dir;
    //printf("thi is the plane normal (%lf, %lf, %lf)\n", obj->normal.x, obj->normal.y, obj->normal.z);

    light_dir = unit_vec3(substract_vec3(light->pos, point));
   // printf("thi is the light dir  (%lf, %lf, %lf)\n",light_dir.x,light_dir.y,light_dir.z);
    dotLN = fmax(0, dot_product(&obj->normal, &light_dir));
    diffuse = scalar_mult(obj->color, light->bright * dotLN);
    
    return diffuse;
}
void   get_normal_and_color(t_vec3 hitpoint, t_obj **object)
{

    if  ((*object)->id == SP)
    {
        (*object)->color = (*object)->shape.sp->color;
        (*object)->normal = unit_vec3(substract_vec3(hitpoint, (*object)->shape.sp->center));
       
    }
    else if ((*object)->id == PL)
    {
        (*object)->color = (*object)->shape.pl->color;
        (*object)->normal = (*object)->shape.pl->normal;
    }
    
}

uint32_t    get_full_color(t_ray ray, t_scene *sc, t_light **light)
{
   t_rgb full;
   t_rgb I_amb;
   t_rgb diffuse;
   t_light *lighter;
   t_rgb specular;
    
    lighter = *light;
    get_normal_and_color(ray.hit_point, &ray.object);
    while (lighter)
    {
      //  printf("this is lit %p\n", lighter);
        I_amb =  get_ambient_color(ray.object->color, sc);
	      diffuse = get_diffuse_color(ray.object, lighter, ray.hit_point);
        specular = get_specular_color(ray.object, lighter, ray.hit_point, sc->camera);
        full = add_vec3(add_vec3(I_amb, diffuse), specular);
        lighter = lighter->next;
       (void)full; 
    }
    return (gradient_color(full));
}

uint32_t get_phong_effect(t_ray ray, t_scene *scene)
{
    t_light     **light;
    uint32_t    finished;

    light = &scene->light;
    finished = get_full_color(ray, scene, light);
    return (finished);
}

/*t_vec3 reflect_vec(t_vec3 light_dir, t_vec3 normal)
{
    return substract_vec3(
        scalar_mult(normal, 2 * dot_product(&light_dir, &normal)), 
        light_dir);
}*/
