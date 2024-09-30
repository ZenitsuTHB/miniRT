#<-------------------------------|VARIABLES|---------------------------------->#

NAME		= miniRT
CC			= cc
CFLAGS		= -Wextra -Wall -Werror -I .
MLXFLAGS	= -ldl -lglfw -pthread -lm

#<-------------------------------|LIBRARIES|---------------------------------->#

MLX		= libmlx42.a
MLX_D	= ./libs/MLX42/build/
LIBFT	= libft.a
LIBFT_D	= ./libs/libft/

#<---------------------------------|FILES|------------------------------------>#

SRC_D	= ./src/
SRC_F	= main.c parser/file.c parser/parser_utils.c parser/set_data.c \
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

$(OBJ_D)%.o: $(SRC_D)%.c Makefile
	$(CC) $(CFLAGS) -MMD -o $@ -c $<
	mv ${@:.o=.d} ${DEP_D}

$(NAME): $(DEP_D) $(OBJ_D) $(OBJ)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) $(MLX_D)$(MLX) $(LIBFT_D)$(LIBFT) -o $(NAME)

#<------------------------------|DIRECTORIES|--------------------------------->#

$(DEP_D):
	mkdir $(DEP_D)

$(OBJ_D):
	mkdir $(OBJ_D)
	mkdir $(OBJ_D)parser

$(MLX_D):
	mkdir $(MLX_D)

#<---------------------------------|PHONY|------------------------------------>#

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
