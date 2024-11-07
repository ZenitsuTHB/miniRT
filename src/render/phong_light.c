/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/07 01:27:10 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>
#include <math.h>

// reflecdirection = light_dir - 2 * (normal * light_dir) * normal;
// Final specular color (light color * intensity * specular factor)
t_rgb	get_specular_color(t_obj *obj, t_light *light, t_vec3 point,
		t_camera *cam)
{
	double	spec;
	t_vec3	normal;
	t_vec3	light_dir;
	t_vec3	reflect_dir;
	t_vec3	view_dir;

	spec = 0.0;
	normal = (t_vec3){0, 0, 0};
	normal = obj->normal;
	view_dir = unit_vec3(substract_vec3(point, cam->origin));
	light_dir = unit_vec3(substract_vec3(point, light->pos));
	reflect_dir = reflect_vec(light_dir, normal);
	spec = pow(fmax(dot_product(&view_dir, &reflect_dir), 0.0), 32.9);
	return (scalar_mult(light->color, light->bright * spec));
}

// AmbL = basecolor * Iamb;
t_rgb	get_ambient_color(t_rgb base, t_scene *sc)
{
	t_rgb	i_amb;

	i_amb = scalar_mult(base, sc->ambient->bright);
	return (i_amb);
}

// diffuse = light_intensity * COSINE tEtA(angle(normal, lightdir)) * obj_color;
t_vec3	get_diffuse_color(t_obj *obj, t_light *light, t_vec3 point)
{
	double	dot_ln;
	t_vec3	diffuse;
	t_vec3	light_dir;

	light_dir = unit_vec3(substract_vec3(light->pos, point));
	dot_ln = fmax(0, dot_product(&obj->normal, &light_dir));
	diffuse = scalar_mult(obj->color, light->bright * dot_ln);
	return (diffuse);
}

uint32_t	get_full_color(t_ray ray, t_scene *sc, t_light **light, t_obj *obj)
{
	t_light	*l;
	t_vec3	point;
	t_phong	vars;

	l = *light;
	point = ray.hit_point;
	ft_bzero(&vars, sizeof(t_phong));
	get_normal_and_color(ray.hit_point, &ray.object);
	while (l)
	{
		l->direction = unit_vec3(substract_vec3(point, l->pos));
		vars.i_amb = get_ambient_color(ray.object->color, sc);
		if (is_shadowed(l->pos, l->direction, obj, ray))
			vars.full = vars.i_amb;
		else
		{
			vars.diff = get_diffuse_color(ray.object, l, point);
			vars.spec = get_specular_color(ray.object, l, point, sc->camera);
			vars.full = add_vec3(add_vec3(vars.spec, vars.diff), vars.i_amb);
		}
		vars.finished = accumulation_color(vars.finished, vars.full);
		vars.full = (t_rgb){0, 0, 0};
		l = l->next;
	}
	return (gradient_color(clamp_color(vars.finished)));
}

uint32_t	get_phong_effect(t_ray ray, t_scene *scene, t_obj *obj)
{
	t_light		**light;
	uint32_t	phong_color;

	light = &scene->light;
	phong_color = get_full_color(ray, scene, light, obj);
	return (phong_color);
}
