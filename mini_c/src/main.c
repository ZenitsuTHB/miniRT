
#include <minirt.h>

int main(void)
{
  t_win init;

  init.mlx_connection = mlx_init(HEIGHT, WIDTH, "miniRT", true);
  if (init.mlx_connection == NULL)
    return (1);
  mlx_loop(init.mlx_connection);
  mlx_terminate(init.mlx_connection);
  free(init.mlx_connection);

	//printf("\n\nHALLO miniRT\n\n");
	return (EXIT_SUCCESS);
}
