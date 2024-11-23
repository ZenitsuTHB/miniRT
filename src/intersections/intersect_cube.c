/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:51:00 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/23 13:54:20 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

#include <math.h>
#include <float.h>
#include <stdbool.h>

t_ray hit_cube(t_vec3 dir, t_vec3 origin, t_cube *cube) {
    t_ray ray;
    double tmin = -DBL_MAX;
    double tmax = DBL_MAX;
    double half_size = cube->size / 2.0;
	t_vec3	tmp;

    // Definir el sistema de coordenadas local basado en la normal
    t_vec3 local_origin = substract_vec3(origin, cube->center);  // Origen del rayo transformado al sistema local

    // Normal del cubo para orientar las caras
    t_vec3 normal = cube->normal;

    // Generamos los ejes ortogonales al vector normal (usando cross products)
	tmp = (t_vec3){1, 0, 0};
    t_vec3 local_x = cross_product(&normal, &tmp);
	tmp = (t_vec3){0, 1, 0};
    if (dot_product(&local_x, &local_x) < 1e-6) {  // Si la normal está alineada con el eje X
        local_x = cross_product(&normal, &tmp);
    }
    t_vec3 local_y = cross_product(&normal, &local_x);
    local_x = unit_vec3(local_x);
    local_y = unit_vec3(local_y);
    normal = unit_vec3(normal);

    // Transformar el rayo al sistema local usando los ejes generados
    double ray_x = dot_product(&local_origin, &local_x);
    double ray_y = dot_product(&local_origin, &local_y);
    double ray_z = dot_product(&local_origin, &normal);

    double dir_x = dot_product(&dir, &local_x);
    double dir_y = dot_product(&dir, &local_y);
    double dir_z = dot_product(&dir, &normal);

    // Revisar intersección con cada cara del cubo
    for (int i = 0; i < 3; i++) {
        // Determinar las intersecciones en los ejes locales
        double inv_dir = 1.0 / (i == 0 ? dir_x : (i == 1 ? dir_y : dir_z));
        double bound_min = (i == 0 ? -half_size : (i == 1 ? -half_size : -half_size));
        double bound_max = (i == 0 ? half_size : (i == 1 ? half_size : half_size));

        double t1 = (bound_min - (i == 0 ? ray_x : (i == 1 ? ray_y : ray_z))) * inv_dir;
        double t2 = (bound_max - (i == 0 ? ray_x : (i == 1 ? ray_y : ray_z))) * inv_dir;

        if (t1 > t2) {
            double tmp = t1;
            t1 = t2;
            t2 = tmp;
        }

        tmin = fmax(tmin, t1);
        tmax = fmin(tmax, t2);

        if (tmin > tmax) {
            ray.hit = false;
            return ray;
        }
    }

    // Si tmin > 0, entonces hay una intersección
    if (tmin > 0) {
        ray.hit = true;
        ray.distance = tmin;
        ray.hit_point = add_vec3(origin, scalar_mult(dir, tmin)); // Punto de impacto
    } else {
        ray.hit = false;
    }
    return ray;
}

