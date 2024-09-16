/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:36:45 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/11 18:54:21 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parser.h"
#include "../../headers/minirt.h"

int set_color(char *color, t_rgb *rgb)
{
    char **split_color;

    if (!color)
        return (1);
    split_color = ft_split(color, ',');
    if (!split_color)
        return (1);
    rgb->red = ft_atoi(split_color[0]);
    if (rgb->red < 0 || rgb->red > 255)
        return (free_split(split_color), 1);
    rgb->green = ft_atoi(split_color[1]);
    if (rgb->green < 0 || rgb->green > 255)
        return (free_split(split_color), 1);
    rgb->blue = ft_atoi(split_color[2]);
    if (rgb->blue < 0 || rgb->blue > 255)
        return (free_split(split_color), 1);
    free_split(split_color);
    return (0);
}

int set_posicion(char *pos, t_vec *vec)
{
    char **split_pos;

    if (!pos)
        return (1);
    split_pos = ft_split(pos, ',');
    if (!split_pos)
        return (1);
    vec->x = 0;//ft_float_atoi(split_pos[0]);
    vec->y = 0;//ft_float_atoi(split_pos[1]);
    vec->z = 0;//ft_float_atoi(split_pos[2]);
    free_split(split_pos);
    return (0);
}

int set_normal(char *normal, t_vec *vec)
{
    char **split_normal;

    if (!normal)
        return (1);
    split_normal = ft_split(normal, ',');
    if (!split_normal)
        return (1);
    vec->x = 0;//ft_float_atoi(split_normal[0]);
    if (vec->x < -1.0 || vec->x > 1.0)
        return (free_split(split_normal), 1);
    vec->y = 0;//ft_float_atoi(split_normal[1]);
    if (vec->y < -1.0 || vec->y > 1.0)
        return (free_split(split_normal), 1);
    vec->z = 0;//ft_float_atoi(split_normal[2]);
    if (vec->z < -1.0 || vec->z > 1.0)
        return (free_split(split_normal), 1);
    free_split(split_normal);
    return (0);
}

int set_light_struct(char *light, double *bright)
{
	light++;
    *bright = 0.0;//ft_float_atoi(light);
    if (*bright < 0.0 || *bright > 1.0)
        return (1);
    return (0);
}
