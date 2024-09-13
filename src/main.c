/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:46:30 by avolcy            #+#    #+#             */
/*   Updated: 2024/09/13 21:00:20 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
# include <../libs/MLX42/include/MLX42/MLX42.h>

int init_scene(t_scene *scene)
{

	scene->planes->origin = create_vect(0.0, 0.0, 0.0);
	scene->planes->normal = create_vect(0.0, 0.0, 0.0);
	
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	t_mlx	mlx;
	t_scene scene; 
	
	init_scene(&scene);//ARCHLY
	if (init_window(&mlx))
		return (error_message( YEL ,ERROR_WIND));
	mlx_key_hook(mlx.con, &manage_escape, &mlx);
	render_object(&scene);
	mlx_loop(mlx.con);
	mlx_terminate(mlx.con);
	return (EXIT_SUCCESS);
}
