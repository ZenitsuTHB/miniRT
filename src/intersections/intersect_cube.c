/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:51:00 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/23 15:01:56 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

double	chk_int(double dir[3], double ray[3], double half_size, double tm[2])
{
	int		i;
	double	inv_dir;
	double	bound[2];
	double	t[3];

	i = 0;
	while (i < 3)
	{
		inv_dir = 1.0 / (i == 0 ? dir[0] : (i == 1 ? dir[1] : dir[2]));
		bound[0] = (i == 0 ? -half_size : (i == 1 ? -half_size : -half_size));
		bound[1] = (i == 0 ? half_size : (i == 1 ? half_size : half_size));
		t[0] = (bound[0] - (i == 0 ? ray[0] : (i == 1 ? ray[1] : ray[2]))) * inv_dir;
		t[1] = (bound[1] - (i == 0 ? ray[0] : (i == 1 ? ray[1] : ray[2]))) * inv_dir;
		if (t[0] > t[1])
		{
			t[2] = t[0];
			t[0] = t[1];
			t[1] = t[2];
		}
		tm[0] = fmax(tm[0], t[0]);
		tm[1] = fmin(tm[1], t[1]);
		if (tm[0] > tm[1])
			return (-1);
		i++;
	}
	return (tm[0]);
}

void	calculate_local_axes(t_vec3 normal, t_vec3 *local_x, t_vec3 *local_y)
{
	t_vec3	tmp;

	tmp = (t_vec3){1, 0, 0};
	*local_x = cross_product(&normal, &tmp);
	tmp = (t_vec3){0, 1, 0};
	if (dot_product(local_x, local_x) < 1e-6)
		*local_x = cross_product(&normal, &tmp);
	*local_y = cross_product(&normal, local_x);
	*local_x = unit_vec3(*local_x);
	*local_y = unit_vec3(*local_y);
	normal = unit_vec3(normal);
}

t_ray	hit_cube(t_vec3 dir, t_vec3 origin, t_cube *cu)
{
	t_ray	ray;
	double	t[2];
	double	half_size;
	t_vec3	local_origin;
	t_vec3	normal;
	t_vec3	local[2];
	double	ray_p[3];
	double	dir_p[3];

	normal = cu->normal;
	half_size = cu->size / 2.0;
	local_origin = substract_vec3(origin, cu->center);
	t[0] = -DBL_MAX;
	t[1] = DBL_MAX;
	ray.hit = false;
	calculate_local_axes(normal, &local[0], &local[1]);
	ray_p[0] = dot_product(&local_origin, &local[0]);
	ray_p[1] = dot_product(&local_origin, &local[1]);
	ray_p[2] = dot_product(&local_origin, &normal);
	dir_p[0] = dot_product(&dir, &local[0]);
	dir_p[1] = dot_product(&dir, &local[1]);
	dir_p[2] = dot_product(&dir, &normal);
	t[0] = chk_int(dir_p, ray_p, half_size, t);
	if (t[0] <= 0)
		return (ray);
	ray.hit = true;
	ray.hit_point = add_vec3(origin, scalar_mult(dir, t[0]));
	return (ray);
}
