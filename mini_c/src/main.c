
#include <minirt.h>

int main(void)
{
  t_win init;

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
  free(init.mlx_connection);

	//printf("\n\nHALLO miniRT\n\n");
	return (EXIT_SUCCESS);
}
