#include "math.h"           // Para sqrt y fabs
#include "../../include/minirt.h"


t_vec3 calculate_normal(t_cylinder *cy, t_vec3 hit_point)
{
    t_vec3 hit_to_base = substract_vec3(hit_point, cy->pos);
    double projection = dot_product(&hit_to_base, &cy->normal);

    // Check if point is on the side surface
    if (projection > 0 && projection < cy->height)
    {
        // Find the closest point on the cylinder axis to the hit point
        t_vec3 closest_point_on_axis = add_vec3(cy->pos, scalar_mult(cy->normal, projection));
        
        // Calculate the normal by subtracting the axis point from the hit point
        t_vec3 normal = substract_vec3(hit_point, closest_point_on_axis);
        
        // Normalize the resulting vector to get the surface normal
        return unit_vec3(normal);
    }
    else
    {
        // Point is on a cap
        if (projection <= 0)
        {
            // Bottom cap normal
            return scalar_mult(cy->normal, -1);
        }
        else
        {
            // Top cap normal
            return cy->normal;
        }
    }
}


// Función auxiliar para calcular la intersección del rayo con las tapas del cilindro
bool check_cylinder_caps(t_vec3 direction, t_vec3 origin, t_cylinder *cy, double *t_cap, t_vec3 *cap_hit_point)
{
    double d;
    t_vec3 cap_center;
    t_vec3 point_on_plane;

    // Comprobar la tapa inferior
    cap_center = cy->pos; // La posición es el centro de la tapa inferior
    d = dot_product(&cy->normal, &direction);

    // Comprobar si el rayo es paralelo a la tapa
    if (fabs(d) > 1e-6)
    {
        t_vec3 ddd = substract_vec3(cap_center, origin);
        double t = dot_product(&cy->normal, &ddd ) / d;
        if (t > 0)
        {
            point_on_plane = add_vec3(origin, scalar_mult(direction, t));
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
    d = dot_product(&cy->normal, &direction);
    if (fabs(d) > 1e-6)
    {
        t_vec3 ddd = substract_vec3(cap_center, origin);
        double t = dot_product(&cy->normal, &ddd ) / d;
        if (t > 0)
        {
            point_on_plane = add_vec3(origin, scalar_mult(direction, t));
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
                ray.normal = calculate_normal(cy, ray.hit_point);
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
            ray.normal = (dot_product(&direction, &cy->normal) < 0) ? cy->normal : scalar_mult(cy->normal, -1);
        }
    }

    return ray;
}
