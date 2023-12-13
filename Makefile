NAME	:= fractol

CFLAGS	:= -Wextra -Wall -Werror

MLX	:= MLX42-master

HEADERS	:= -I ./$(MLX) -I ./

LIBS	:= $(MLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCDIR := ./src/

SRCS	:=  $(SRCDIR)main.c\
				$(SRCDIR)julia.c\
				$(SRCDIR)mandelbrot.c\
				$(SRCDIR)coloring.c\
				$(SRCDIR)external_input.c\

OBJS	:= ${SRCS:.c=.o}

CC		:= cc

.PHONY: all, clean, fclean, re, libmlx, libft

all: libmlx libft $(NAME)

libft:
	@make -C ./Libft00

ft_printf01:
	@make -C ./ft_printf01-master

libmlx:
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<) \n"

$(NAME): $(OBJS) libft ft_printf01
	@$(CC) $(OBJS) $(LIBS) ./Libft00/libft.a ./ft_printf01-master/ft_printf.a -o $(NAME)

clean:
	@make -C ./Libft00 clean
	@make -C ./ft_printf01-master clean
	@rm -rf $(OBJS)
	@rm -rf $(MLX)/build

fclean: clean
	@make -C ./Libft00 fclean
	@make -C ./ft_printf01-master fclean
	@rm -rf $(NAME)

re: fclean all