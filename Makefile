NAME	:= miniRT
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g 
LIBMLX	:= libs/MLX42
LIBFT	:= libs/libft

OBJS_DIR := ./build

INC = ./include/minirt.h
INC += ./include/macros.h
INC += ./include/struct.h
INC += ./include/vector.h
HEADERS	:= -I./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBS    += $(LIBFT)/libft.a

SRCSDIR := ./src
SRCS	:= main.c vector_op.c mlx_use.c rendering.c camera.c vector_op1.c vector_op2.c intersections.c parser/file.c parser/parser_utils.c parser/set_data.c \
		   parser/set_setup.c parser/set_objects.c parser/set_utils.c \
		   parser/create_setup.c parser/set_aux.c free_scene.c \
		   print_scene.c draw.c

OBJ_D	= ./objects/
OBJ_F	= $(SRC_F:.c=.o)
OBJ 	= $(addprefix $(OBJ_D), $(OBJ_F))

DEP_D	= ./dependencies/
DEP_F	= $(SRC_F:.c=.d)
DEP		= $(addprefix $(DEP_D), $(DEP_F))

#<---------------------------------|RULES|------------------------------------>#

all: libmlx libft $(NAME)

libft:
	make -C $(LIBFT_D)

libmlx: $(MLX_D)
	cmake ./libs/MLX42 -B $(MLX_D) && make -C $(MLX_D) -j4

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 

$(OBJS_DIR)/%.o: $(SRCSDIR)/%.c Makefile $(INC)
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
	make fclean -C $(LIBFT_D)
	rm -rf $(NAME)

re: clean all

-include $(DEP)

.PHONY: all clean fclean re libmlx
#<---------------------------------------------------------------------------->#
