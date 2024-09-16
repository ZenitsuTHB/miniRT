/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:56:49 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/11 18:47:39 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/parser.h"

static int set_light(t_light *light, char *str)
{
    char **split;

    printf("Light: %s\n", str);
    split = ft_split(str, ' ');
	if (!split)
		return (1);
    // Posicion
    if (set_posicion(split[1], &light->pos))
        return (free_split(split), 1);
    // Light
    if (set_light_struct(split[2], &light->brightness))
        return (free_split(split), 1);
    // Color (Bonus)
    if (set_color(split[3], &light->color))
        return (free_split(split), 1);
    free_split(split);
    return (0);
}

static int set_camera(t_cam *cam, char *str)
{
    char **split;

    printf("Camera: %s\n", str);
    split = ft_split(str, ' ');
	if (!split)
		return (1);
    // Posicion
    if (set_posicion(split[1], &cam->pos))
        return (free_split(split), 1);
    // Normal (-1, 1)
    if (set_normal(split[2], &cam->normal))
        return (free_split(split), 1);
    // fov (0, 180)
    cam->fov = ft_atoi(split[3]);
    if (cam->fov < 0 || cam->fov > 180)
        return (free_split(split), 1);
    free_split(split);
    return (0);
}

static int set_ambient(t_ambient *amb, char *str)
{
    char **split;

    printf("Ambient: %s\n", str);
    split = ft_split(str, ' ');
    if (!split)    
		return (1);
	// Light
    if (set_light_struct(split[1], &amb->light))
        return (free_split(split), 1);
	// Color
    if (set_color(split[2], &amb->color))
        return (free_split(split), 1);
    free_split(split);
    return (0);
}

static int put_data_struct(char *id, char *data, t_scene *scene)
{
    static int sp = 0;
    static int pl = 0;
    static int cy = 0;
    static int co = 0;
	
    if (!ft_strncmp(id, "A", 1))
        return (set_ambient(scene->ambient, data));
    else if (!ft_strncmp(id, "C", 1))
        return (set_camera(scene->camera, data));
    else if (!ft_strncmp(id, "L", 1))
        return (set_light(scene->light, data));
    else if (!ft_strncmp(id, "sp", 2))
        return (set_sphere(&scene->spheres[sp++], data));
    else if (!ft_strncmp(id, "pl", 2))
        return (set_plane(&scene->planes[pl++], data));
    else if (!ft_strncmp(id, "cy", 2))
        return (set_cylinder(&scene->cylinders[cy++], data));
    else if (!ft_strncmp(id, "co", 2))
        return (set_cone(&scene->cones[co++], data));
    else
        return (1);
}

int put_data(t_scene *scene, char **ids, char **data)
{
    int i;

    i = 0;
    while (data[i])
    {
        if (put_data_struct(ids[i], data[i], scene))
            return (1);
        i++;
    }
    return (0);
}
