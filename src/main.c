/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:45:16 by avolcy            #+#    #+#             */
/*   Updated: 2024/08/29 16:58:40 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/minirt.h"

int			error_message(char *color, char *msg)
{
	printf(RED"\n\tError\n");
	printf("\t%s%s\n\n"NC, color, msg);
	return (-1);
}

int check_args(int argc, char *scene)
{
	int i;

	i = 0;
	if (argc != 2)
		return (error_message(YEL, ERROR_ARG));
	//check the extensions is correct 
	printf("ARGUMENT : %s\n", scene);
	if (scene[0] == '.')
		i++;
	while (scene[i] && scene[i] != '.')
		i++;
	printf("extension : %s\n", &scene[i]);

	printf("len of file %ld\n", ft_strlen(&scene[i]));
	printf("return value of strcpim  %d\n", ft_strncmp(&scene[i], ".rt", 4));
	if (ft_strncmp(&scene[i], ".rt", 4) != 0 || ft_strlen(scene) <= 3)
	{
		if (ft_strlen(scene) <= 3)
			return (error_message(YEL, "Only extension ! file name missed."));
		return (error_message(YEL, ERROR_EXTENSION));
	}


	//check for file permision, Open file and 
	//check if the file format meet the subject requirements
	//open, close, read, write,
	//printf, malloc, free, perror,
	//strerror, exit
	
	return 0;
}

//bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param)
//static void mlx_render_images(mlx_t* mlx)
//void mlx_close_window(mlx_t* mlx)
//void mlx_delete_image(mlx_t* mlx, mlx_image_t* image)
//mlx_image_t* mlx_new_image(mlx_t* mlx, uint32_t width, uint32_t height)
//int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x, int32_t y)
//void mlx_set_instance_depth(mlx_instance_t* instance, int32_t zdepth)

int main(int argc, char *argv[])
{
	t_win init;

	if (check_args(argc, argv[1]) == -1)
		return (1);
	init.mlx_connection = NULL;
	init.mlx_connection = mlx_init(HEIGHT, WIDTH, "miniRT", true);
	if (init.mlx_connection == NULL)
		return (1);

	mlx_loop(init.mlx_connection);

	mlx_terminate(init.mlx_connection);

	//printf("\n\nHALLO miniRT\n\n");
	return (EXIT_SUCCESS);
}
