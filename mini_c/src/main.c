/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:45:16 by avolcy            #+#    #+#             */
/*   Updated: 2024/08/26 18:54:11 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <minirt.h>

int check_args(int argc, char *scene)
{
	int i;

	i = 0;
	if (argc != 2)
	{
		printf(RED"\n\t%s\n\n"NC, ERROR_ARG);
		return (-1);
	}
	//check the extensions is correct 
	printf("ARGUMENT : %s\n", scene);
	while (scene[i] && scene[i] != '.')
		i++;
	printf("extension : %s\n", &scene[i]);
	
	if (ft_strncmp(&scene[i], ".rt", 4))
	{
		printf(YEL"\n\t%s\n\n"NC, ERROR_EXTENSION);
		return (-1);
	}

	//check for file permision, Open file and 
	//check if the file format meet the subject requierments
	
	return 0;
}

int main(int argc, char *argv[])
{
  t_win init;

  if (check_args(argc, argv[1]) == -1)
	  return (1);








  init.mlx_connection = NULL;
  init.mlx_connection = mlx_init(HEIGHT, WIDTH, "miniRT", true);
  if (init.mlx_connection == NULL)
    return (1);




  //bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param)
  //static void mlx_render_images(mlx_t* mlx)
  //void mlx_close_window(mlx_t* mlx)
  //void mlx_delete_image(mlx_t* mlx, mlx_image_t* image)
  //mlx_image_t* mlx_new_image(mlx_t* mlx, uint32_t width, uint32_t height)
  //int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x, int32_t y)
  //void mlx_set_instance_depth(mlx_instance_t* instance, int32_t zdepth)
  



  mlx_loop(init.mlx_connection);
  mlx_terminate(init.mlx_connection);

	//printf("\n\nHALLO miniRT\n\n");
	return (EXIT_SUCCESS);
}
