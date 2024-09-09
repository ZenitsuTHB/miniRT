NAME	:= miniRT
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast 
LIBMLX	:= libs/MLX42
LIBFT	:= libs/libft

OBJS_DIR := ./build

INC := ./include/minirt.h
HEADERS	:= -I./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBS    += $(LIBFT)/libft.a
SRCSDIR := ./src

SRCS	:= main.c vector_op.c

OBJS	:= $(addprefix $(OBJS_DIR)/, ${SRCS:.c=.o})

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

re: clean all

.PHONY: all, clean, fclean, re, libmlx
