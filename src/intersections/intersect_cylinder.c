/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:54:54 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/21 14:06:12 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/*

	Cilindro

		- Area = 2πrh + 2πr² = 2πr(h + r);
		- Volumen = πr²h;


	pos: Coordenadas del centro de la base

	1- Dibujar un circulo en pos->z como centro
		- x = pos->x + r * cos(0-360)
		- y = pos->y + r * sin(0-360)
	2- Mirar la normal para ver la direccion donde pintar
	3- Ejemplo: pos->z = 20.6 Altura = 21.42 Normal 0,0,1 mira a la z hacia arriba
		- Eleva el circulo n altura en la direccion de la normal
		- z = 20.6 + 21.42 = 42.02

*/

t_ray	hit_cylinder(t_vec3 dir, t_vec3	origin, t_cylinder *cy)
{
}
