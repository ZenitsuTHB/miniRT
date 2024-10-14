NAME	:= miniRT
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g 
LIBMLX	:= libs/MLX42
LIBFT	:= libs/libft

OBJ_D := ./build

INC = ./include/minirt.h
INC += ./include/macros.h
INC += ./include/struct.h
INC += ./include/vector.h
INC += ./include/parser.h
HEADERS	:= -Iinclude -I$(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBS    += $(LIBFT)/libft.a
SRCSDIR := ./src

SRCS	:= main.c free_scene.c print_scene.c mlx_use.c

PARSER	:= file.c parser_utils.c set_data.c set_setup.c \
		   get_objects.c set_aux.c set_objects.c set_utils.c


HIT		:= intersect_sphere.c #intersect_plane.c 

RENDER  := rendering.c camera.c

VECTOR	:= vector_op.c vector_op1.c vector_op2.c

OBJS	:= $(addprefix $(OBJ_D)/, ${SRCS:.c=.o})
OBJS	+= $(addprefix $(OBJ_D)/render/, ${RENDER:.c=.o})
OBJS	+= $(addprefix $(OBJ_D)/vector/, ${VECTOR:.c=.o})
OBJS	+= $(addprefix $(OBJ_D)/parser/, ${PARSER:.c=.o})
OBJS	+= $(addprefix $(OBJ_D)/intersections/, ${HIT:.c=.o})

all: libmlx libft $(NAME)

libft:
	make -C $(LIBFT)

libmlx: $(MLX_D)
	cmake ./libs/MLX42 -B $(MLX_D) && make -C $(MLX_D) -j4

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 

$(OBJ_D)/%.o: $(SRCSDIR)/%.c Makefile $(INC)
	mkdir -p $(dir $@)
	clear
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "\nCompiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -fsanitize=address $(HEADERS) -o $(NAME)


debug: all
	#valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME)
	valgrind --leak-check=full ./$(NAME)


clean:
	rm -rf $(OBJ_D) $(DEP_D)

fclean: clean
	rm -rf $(MLX_D)
	make fclean -C $(LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
