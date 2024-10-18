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

uint32_t    get_ambient_color(uint32_t base, t_scene *sc)
{
    //double      intensity;
    uint32_t    ambient;
(void)sc;
    //intensity = sc->light->bright * sc->ambient->property;
    ambient = base;// * sc->light->bright;
    return(ambient);
}

uint32_t get_phong_effect(t_vec3 dir, t_ray ray, t_scene *scene)
{
    uint32_t finished;
    uint32_t tmp_color;

    (void)dir;
    tmp_color = ray.object->shape.sp->color.gradient;
    if (ray.object->id == SP)
		finished = get_ambient_color(tmp_color, scene);
	else if (ray.object->id == PL)
		finished = ray.object->shape.pl->color.gradient;
	else
		finished = 0xFF;
    return (finished);
}