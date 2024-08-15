NAME	:= miniRT
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= libs/MLX42

OBJS_DIR := ./build

HEADERS	:= -I ./include -I $(LIBMLX)/include -I ./headers/
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCSDIR := ./src

SRCS	:= main.c

OBJS	:= $(addprefix $(OBJS_DIR)/, ${SRCS:.c=.o})

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJS_DIR)/%.o: $(SRCSDIR)/%.c $(HEADER) Makefile
	mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "\nCompiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME) $(OBJS_DIR)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
