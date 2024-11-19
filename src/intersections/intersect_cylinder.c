/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:54:54 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/19 13:03:28 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

bool check_cylinder_caps(t_vec3 dir, t_vec3 origin, t_cylinder *cy, double *t_cap, t_vec3 *cap_hit_point)
{
    double d;           // Denominador para verificar si el rayo es paralelo al plano de la tapa
    t_vec3 v;           // Vector desde el origen del rayo al centro de la tapa
    double t;           // Distancia de intersección con el plano
    t_vec3 point_on_plane;  // Punto de intersección del rayo con el plano de la tapa
    t_vec3 to_center;   // Distancia entre el punto de intersección y el centro de la tapa

    // Comprobar la tapa inferior
    d = dot_product(&cy->normal, &dir);  // Producto punto entre la normal de la tapa y la dirección del rayo

    // Comprobar si el rayo es paralelo al plano de la tapa
    if (fabs(d) > 1e-6)
    {
        v = substract_vec3(cy->pos, origin);  // Vector desde el origen del rayo al centro de la tapa
        t = dot_product(&cy->normal, &v) / d;  // Distancia de intersección

        if (t > 0)  // Solo consideramos intersecciones hacia adelante (t > 0)
        {
            point_on_plane = add_vec3(origin, scalar_mult(dir, t));  // Punto de intersección

            // Comprobar si el punto está dentro del radio del disco (tapa inferior)
            to_center = substract_vec3(point_on_plane, cy->pos);
            if (dot_product(&to_center, &to_center) <= cy->radius * cy->radius)
            {
                *t_cap = t;
                *cap_hit_point = point_on_plane;
                return true;  // Intersección con la tapa inferior
            }
        }
    }

    // Comprobar la tapa superior
    t_vec3 top_center = add_vec3(cy->pos, scalar_mult(cy->normal, cy->height));  // Centro de la tapa superior
    d = dot_product(&cy->normal, &dir);  // Producto punto con la dirección del rayo

    // Comprobar si el rayo es paralelo al plano de la tapa superior
    if (fabs(d) > 1e-6)
    {
        v = substract_vec3(top_center, origin);  // Vector desde el origen del rayo al centro de la tapa superior
        t = dot_product(&cy->normal, &v) / d;  // Distancia de intersección

        if (t > 0)  // Solo consideramos intersecciones hacia adelante (t > 0)
        {
            point_on_plane = add_vec3(origin, scalar_mult(dir, t));  // Punto de intersección

            // Comprobar si el punto está dentro del radio del disco (tapa superior)
            to_center = substract_vec3(point_on_plane, top_center);
            if (dot_product(&to_center, &to_center) <= cy->radius * cy->radius)
            {
                *t_cap = t;
                *cap_hit_point = point_on_plane;
                return true;  // Intersección con la tapa superior
            }
        }
    }

    return false;  // No hay intersección con ninguna de las tapas
}
/*

bool check_cylinder_caps(t_vec3 dir, t_vec3 origin, t_cylinder *cy, double *t_cap, t_vec3 *cap_hit_point)
{
    double d;
	t_vec3	v;
    t_vec3 cap_center;
    t_vec3 point_on_plane;

    // Comprobar la tapa inferior
    cap_center = cy->pos; // La posición es el centro de la tapa inferior
    d = dot_product(&cy->normal, &dir);

    // Comprobar si el rayo es paralelo a la tapa
    if (fabs(d) > 1e-6)
    {
		v = substract_vec3(cap_center, origin);
        double t = dot_product(&cy->normal, &v) / d;
        if (t > 0)
        {
            point_on_plane = add_vec3(origin, scalar_mult(dir, t));
            if (euclidean_distance(cap_center, point_on_plane) <= pow(cy->radius, 2))
            {
                *t_cap = t;
                *cap_hit_point = point_on_plane;
                return true;
            }
        }
    }

    // Comprobar la tapa superior
    cap_center = add_vec3(cy->pos, scalar_mult(cy->normal, cy->height));
    d = dot_product(&cy->normal, &dir);

    if (fabs(d) > 1e-6)
    {
		v = substract_vec3(cap_center, origin);
        double t = dot_product(&cy->normal, &v) / d;
        if (t > 0)
        {
            point_on_plane = add_vec3(origin, scalar_mult(dir, t));
            if (euclidean_distance(cap_center, point_on_plane) <= pow(cy->radius, 2))
            {
                *t_cap = t;
                *cap_hit_point = point_on_plane;
                return true;
            }
        }
    }

    return false;
}
*/
t_ray hit_cylinder(t_vec3 dir, t_vec3 origin, t_cylinder *cy) {
    t_ray ray;
    t_operation op;
    t_vec3 cy_to_ray_origin;
    double t_cap;
    t_vec3 cap_hit_point;

    ft_bzero(&ray, sizeof(t_ray));
    ray.hit = false;

    // Vector desde el centro del cilindro hasta el origen del rayo
    cy_to_ray_origin = substract_vec3(origin, cy->pos);

    // Cálculo de los coeficientes cuadráticos para el cuerpo del cilindro
    op.A = dot_product(&dir, &dir) - pow(dot_product(&dir, &cy->normal), 2);
    op.B = 2 * (dot_product(&dir, &cy_to_ray_origin) - dot_product(&dir, &cy->normal) * dot_product(&cy_to_ray_origin, &cy->normal));
    op.C = dot_product(&cy_to_ray_origin, &cy_to_ray_origin) - pow(dot_product(&cy_to_ray_origin, &cy->normal), 2) - pow(cy->radius, 2);

    // Depuración de coeficientes
    //printf("A: %f, B: %f, C: %f\n", op.A, op.B, op.C);

    // Discriminante
    op.delta = op.B * op.B - 4 * op.A * op.C;
    if (op.delta >= 0) {
        op.lambda = calculate_quadratic_root(op);
        if (op.lambda > 0) {
            // Punto de intersección en el cuerpo del cilindro
            ray.hit_point = add_vec3(origin, scalar_mult(dir, op.lambda));
            t_vec3 hit_to_base = substract_vec3(ray.hit_point, cy->pos);
            double projection = dot_product(&hit_to_base, &cy->normal);

            // Verificar si el punto de impacto está dentro de la altura del cilindro
            if (projection >= 0 && projection <= cy->height) {
                ray.hit = 1;
                ray.distance = op.lambda;
            }
        }
    }

    if (check_cylinder_caps(dir, origin, cy, &t_cap, &cap_hit_point)) {
        // Si el punto de la tapa es más cercano o si no había intersección previa
        if (!ray.hit || t_cap < ray.distance) {
            ray.hit = 2;
            ray.distance = t_cap;
            ray.hit_point = cap_hit_point;
        }
    }

    return ray;
}
