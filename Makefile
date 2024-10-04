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

SRCS	:= main.c mlx_use.c  init_hard_coded.c

#HIT		:= intersect_plane.c intersect_sphere.c

RENDER  := rendering.c

VECTOR	:= vector_op.c vector_op1.c vector_op2.c

OBJS	:= $(addprefix $(OBJS_DIR)/, ${SRCS:.c=.o})
OBJS	+= $(addprefix $(OBJS_DIR)/render/, ${RENDER:.c=.o})
OBJS	+= $(addprefix $(OBJS_DIR)/vector/, ${VECTOR:.c=.o})
#OBJS	+= $(addprefix $(OBJS_DIR)/intersections/, ${HIT:.c=.o})

all: libmlx libft $(NAME)

libft:
	@make -C $(LIBFT)

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
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)
	@rm -rf $(LIBMLX)/build
	clear

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -rf $(NAME) $(OBJS_DIR)
	clear

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
