

#ifndef MINIRT_H
# define MINIRT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include <../libs/MLX42/include/MLX42/MLX42.h> 

#define WIDTH 1000
#define HEIGHT 1400

typedef struct s_win {

  void* mlx_window;
  void* mlx_connection;
  
} t_win;

// typedef struct s_win {
//
// } t_win;
//

#endif
