/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:07:37 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/11 18:52:53 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"
#include "../../headers/parser.h"

int set_cone(t_cone *cone, char *str)
{
    char **split;

    printf("Cone: %s\n", str);
    split = ft_split(str, ' ');
    if (!split)
        return (1);
    // Pos
    if (set_posicion(split[1], &cone->pos))
        return (free_split(split), 1);
    // Normal
    if (set_normal(split[2], &cone->normal))
        return (free_split(split), 1);
    // Diameter
    //cone->diameter = ft_float_atoi(split[3]);
    // Height
    //cone->height = ft_float_atoi(split[4]);
    // Color
    if (set_color(split[5], &cone->color))
        return (free_split(split), 1);
    free_split(split);
    return (0);
}

int set_cylinder(t_cylinder *cyl, char *str)
{
    char **split;

    printf("Cylinder: %s\n", str);
    split = ft_split(str, ' ');
    if (!split)
        return (1);
    // Pos
    if (set_posicion(split[1], &cyl->pos))
        return (free_split(split), 1);
    // Normal
    if (set_normal(split[2], &cyl->normal))
        return (free_split(split), 1);
    // Diameter
    //cyl->diameter = ft_float_atoi(split[3]);
    // Height
    //cyl->height = ft_float_atoi(split[4]);
    // Color
    if (set_color(split[5], &cyl->color))
        return (free_split(split), 1);
    free_split(split);
    return (0);
}

int set_plane(t_plane *plane, char *str)
{
    char **split;

    printf("Plane: %s\n", str);
    split = ft_split(str, ' ');
    if (!split)
        return (1);
    // Pos
    if (set_posicion(split[1], &plane->pos))
        return (free_split(split), 1);
    // Normal
    if (set_normal(split[2], &plane->normal))
        return (free_split(split), 1);
    // Color
    if (set_color(split[3], &plane->color))
        return (free_split(split), 1);
    free_split(split);
    return (0);
}

int set_sphere(t_sphere *sphere, char *str)
{
    char **split;

    printf("Sphere: %s\n", str);
    split = ft_split(str, ' ');
    if (!split)
        return (1);
    // Posicion
    if (set_posicion(split[1], &sphere->pos))
        return (free_split(split), 1);
    // Diameter
    //sphere->diameter = ft_float_atoi(split[2]);
    // Color
    if (set_color(split[3], &sphere->color))
        return (free_split(split), 1);
    free_split(split);
    return (0);
}
