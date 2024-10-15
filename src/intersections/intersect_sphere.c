/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/15 16:30:14 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

double  calculate_quadratic_root(t_operation op)
{
  double  sqrted_delta;
  
  if (op.delta == 0)
    return (-op.B) / (2.0 * op.A);
  sqrted_delta = sqrt(op.delta);
  op.t[0] = (-op.B - sqrted_delta) / (2.0 * op.A);
  op.t[1] = (-op.B + sqrted_delta) / (2.0 * op.A);
  if (op.t[0] >= 0 && op.t[0] < op.t[1])
    return (op.t[0]);
  else if (op.t[1] >= 0)
    return (op.t[1]);
  return (-1.0);
}

t_ray hit_sphere(t_vec3 direction, t_vec3 origin, t_sphere *sp)
{
  t_ray ray;
  t_operation op;

  ray.hit = false;
	op.OC = substract_vec3(origin, sp->center);
	op.A = dot_product(&direction, &direction);
	op.B = 2.0 * dot_product(&op.OC, &direction);
	op.C = dot_product(&op.OC, &op.OC) - (sp->radius * sp->radius);
  op.delta = op.B * op.B - (4 * op.A * op.C);
  if (op.delta < 0)
    return(ray);
  ray.distance = calculate_quadratic_root(op);
  if (ray.distance < 0)
    return (ray);
  ray.hit = true;
  ray.hit_point =  add_vec3(origin, scalar_mult(direction, ray.distance));
  return (ray); 
}
