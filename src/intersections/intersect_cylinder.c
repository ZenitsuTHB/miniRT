/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:54:54 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/17 18:14:43 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"


/*
t_ray hit_cylinder(t_vec3 dir, t_vec3 origin, t_cylinder *cy)
{
    t_ray       ray;          // Estructura de retorno para el rayo
    t_operation op;         // Estructura de variables cuadráticas
    double      proj;   // Proyección para verificar la altura del impacto
	double		sq;

    // Inicializamos `ray` y `op`
    ft_bzero(&ray, sizeof(t_ray));
    ray.hit = false;

    // Vector desde el origen del rayo hasta el centro de la base del cilindro
    op.OC = substract_vec3(origin, cy->pos);

    // Cálculo de los coeficientes cuadráticos A, B y C
    op.A = dot_product(&dir, &dir) - pow(dot_product(&dir, &cy->normal), 2);
    op.B = dot_product(&op.OC, &dir) - (dot_product(&dir, &cy->normal) * dot_product(&op.OC, &cy->normal));
    op.C = dot_product(&op.OC, &op.OC) - pow(dot_product(&op.OC, &cy->normal), 2) - pow(cy->radius, 2);

    // Discriminante para verificar intersección
    op.delta = op.B * op.B - op.A * op.C;
    if (op.delta < 0)
		return (ray); // No hay intersección real

    // Calcular la raíz cuadrada del discriminante
   	sq = sqrt(op.delta);

    // Encontrar la raíz positiva más cercana
    op.lambda = (-op.B - sq) / op.A;
    if (op.lambda < 0)
    {
        op.lambda = (-op.B + sq) / op.A;
        if (op.lambda < 0)
            return (ray); // Intersección está detrás del origen
    }

    // Calcular el punto de impacto en el cilindro
    ray.hit_point = add_vec3(origin, scalar_mult(dir, op.lambda));

    // Verificar si el punto de impacto está dentro de la altura del cilindro
    t_vec3 hit_to_base = substract_vec3(ray.hit_point, cy->pos);
    proj = dot_product(&hit_to_base, &cy->normal);
    if (proj < 0 || proj > cy->height)
        return (ray); // El impacto está fuera de los límites de altura del cilindro

    // Si está dentro, configuramos los datos de `ray`
    ray.hit = true;
    ray.distance = op.lambda;

    return (ray);
}
*/

double distance_squared(t_vec3 point1, t_vec3 point2) 
{
    return pow(point2.x - point1.x, 2) +
           pow(point2.y - point1.y, 2) +
           pow(point2.z - point1.z, 2);
}

bool check_cylinder_caps(t_vec3 direction, t_vec3 origin, t_cylinder *cy, double *t_cap, t_vec3 *cap_hit_point)
{
    double d;
	t_vec3	v;
    t_vec3 cap_center;
    t_vec3 point_on_plane;

    // Comprobar la tapa inferior
    cap_center = cy->pos; // La posición es el centro de la tapa inferior
    d = dot_product(&cy->normal, &direction);

    // Comprobar si el rayo es paralelo a la tapa
    if (fabs(d) > 1e-6)
    {
		v = substract_vec3(cap_center, origin);
        double t = dot_product(&cy->normal, &v) / d;
        if (t > 0)
        {
            point_on_plane = add_vec3(origin, scalar_mult(direction, t));
            if (distance_squared(cap_center, point_on_plane) <= pow(cy->radius, 2))
            {
                *t_cap = t;
                *cap_hit_point = point_on_plane;
                return true;
            }
        }
    }

    // Comprobar la tapa superior
    cap_center = add_vec3(cy->pos, scalar_mult(cy->normal, cy->height));
    d = dot_product(&cy->normal, &direction);

    if (fabs(d) > 1e-6)
    {
		v = substract_vec3(cap_center, origin);
        double t = dot_product(&cy->normal, &v) / d;
        if (t > 0)
        {
            point_on_plane = add_vec3(origin, scalar_mult(direction, t));
            if (distance_squared(cap_center, point_on_plane) <= pow(cy->radius, 2))
            {
                *t_cap = t;
                *cap_hit_point = point_on_plane;
                return true;
            }
        }
    }

    return false;
}

// Función principal para calcular la intersección de un rayo con un cilindro con tapas
t_ray hit_cylinder(t_vec3 direction, t_vec3 origin, t_cylinder *cy)
{
    t_ray ray;
    t_operation op;
    t_vec3 cy_to_ray_origin;
    double lambda;
    double t_cap;
    t_vec3 cap_hit_point;

    ft_bzero(&ray, sizeof(t_ray));
    ray.hit = false;

    // Vector desde el centro del cilindro hasta el origen del rayo
    cy_to_ray_origin = substract_vec3(origin, cy->pos);

    // Cálculo de los coeficientes cuadráticos para el cuerpo del cilindro
    op.A = dot_product(&direction, &direction) - pow(dot_product(&direction, &cy->normal), 2);
    op.B = 2 * (dot_product(&direction, &cy_to_ray_origin) - dot_product(&direction, &cy->normal) * dot_product(&cy_to_ray_origin, &cy->normal));
    op.C = dot_product(&cy_to_ray_origin, &cy_to_ray_origin) - pow(dot_product(&cy_to_ray_origin, &cy->normal), 2) - pow(cy->radius, 2);

    // Discriminante
    op.delta = op.B * op.B - 4 * op.A * op.C;
    if (op.delta >= 0)
    {
        lambda = calculate_quadratic_root(op);
        if (lambda > 0)
        {
            // Punto de intersección en el cuerpo del cilindro
            ray.hit_point = add_vec3(origin, scalar_mult(direction, lambda));
            t_vec3 hit_to_base = substract_vec3(ray.hit_point, cy->pos);
            double projection = dot_product(&hit_to_base, &cy->normal);

            // Verificar si el punto de impacto está dentro de la altura del cilindro
            if (projection >= 0 && projection <= cy->height)
            {
                ray.hit = true;
                ray.distance = lambda;
            }
        }
    }

    // Verificar las tapas del cilindro
    if (check_cylinder_caps(direction, origin, cy, &t_cap, &cap_hit_point))
    {
        // Si el punto de la tapa es más cercano o si no había intersección previa
        if (!ray.hit || t_cap < ray.distance)
        {
            ray.hit = true;
            ray.distance = t_cap;
            ray.hit_point = cap_hit_point;
        }
    }

    return ray;
}
