/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/26 18:28:50 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <../libs/MLX42/include/MLX42/MLX42.h>

bool	hit_sphere(t_ray *ray, t_sphere *sp, double *t)
{
	t_vec3  oc;
	double  res[2];
	double  coef[3];
  double  delta;

	oc = substract_vec3(ray->direction, sp->center);
	coef[0] = dot_product(&ray->direction, &ray->direction);//a
	coef[1] = 2.0 * dot_product(&oc, &ray->direction);//b
	coef[2] = dot_product(&oc, &oc) - (sp->radius * sp->radius);//c
  delta = coef[1] * coef[1] - 4 * coef[0] * coef[2];
  if (delta <0)
    return(false);
  res[0] = (-coef[1] - sqrt(delta)) / (2.0 * coef[0]);
  res[1] = (-coef[1] + sqrt(delta)) / (2.0 * coef[0]);
  if (res[0] > 0 || res[1] > 0)
  {
    if (res[0] < *t)
      *t = res[0];
    else if (res[1] < *t)
      *t = res[1];
    return (true);
  }
  return (false); 
}
