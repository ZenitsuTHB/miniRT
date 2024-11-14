/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:54:54 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/14 23:23:26 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int calculate_abcd(t_operation *op, t_cylinder *cy, t_vec3 dir, t_vec3 cyo)
{
    double dot_dir_dir;
    double dot_dir_cyo;
    double dot_cyo_cyo;
    double dot_cyo_normal;
    double dot_dir_normal;

	dot_dir_dir = dot_product(&dir, &dir);
	dot_dir_normal = dot_product(&dir, &cy->normal);
    dot_cyo_normal = dot_product(&cyo, &cy->normal);
    dot_dir_cyo = dot_product(&dir, &cyo);
    dot_cyo_cyo = dot_product(&cyo, &cyo);
    op->A = dot_dir_dir - (dot_dir_normal * dot_dir_normal);
    op->B = 2 * (dot_dir_cyo - dot_dir_normal * dot_cyo_normal);
    op->C = dot_cyo_cyo - (dot_cyo_normal * dot_cyo_normal)
	 - (cy->radius * cy->radius);
    op->delta = op->B * op->B - 4 * op->A * op->C;
    if (op->delta < 0)
        return (1);
    return (0);
}

// Calculate the point on the cylinder axis closest to the hit point.
// Return the unit vector of the computed normal.
// Compute the normal by finding the vector from the axis to the hit point.
t_vec3 get_cyl_normal(t_vec3 hp, t_cylinder *cy, double m)
{	
    t_vec3 axis_offset;
    t_vec3 axis_point;
    t_vec3 normal_vec;
	
	axis_offset = scalar_mult(cy->normal, m);
	axis_point = add_vec3(cy->pos, axis_offset);
	normal_vec = substract_vec3(hp, axis_point);    
    return unit_vec3(normal_vec);
}


void	check_intersection(t_ray *ray, t_operation op, t_cylinder *cy)
{
	double	a;
	double	b;
	double	m;

	if (op.lambda > 0)
	{
		a = dot_product(&op.tri.dir, &cy->normal);
		b = dot_product(&op.tri.co, &cy->normal);
		m = a * op.lambda + b;
		if (m >= 0 && m <= cy->height)
		{
			ray->hit = true;
			ray->distance = op.lambda;
			ray->hit_point =  add_vec3(op.tri.origin, 
			scalar_mult(op.tri.dir, op.lambda));
			ray->normal = get_cyl_normal(ray->hit_point, cy, m);
		}
		//print_vec3(ray->normal);
	}
}

t_ray	hit_cylinder(t_vec3 dir, t_vec3 origin, t_cylinder *cy)
{
	t_ray		ray;
	t_operation	op;

	ft_bzero(&ray, (sizeof(t_ray)));
	ft_bzero(&op, (sizeof(t_operation)));
	ray.hit = false;
	ray.distance = INFINITY;
	op.tri.dir = dir;
	op.tri.origin = origin;
	op.tri.co = substract_vec3(cy->pos, origin);
	if (calculate_abcd(&op, cy, dir, op.tri.co))
		return (ray);
	op.lambda = calculate_quadratic_root(op);
	if (op.lambda < 0)
		return (ray);
	check_intersection(&ray, op, cy);
	return (ray);
}
