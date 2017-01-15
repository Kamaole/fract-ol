NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o2 -funroll-loops -march=native -lpthread

SRC = src/main.c src/mandlebrot.c src/make_mlx.c src/julia.c src/pixel_to_img.c src/line.c src/rotate.c src/run_fractals.c src/handle_keys.c src/handle_mouse.c src/thread.c src/tree.c src/color.c src/handle_expose.c src/make_hooks.c
FRAMEWORKS = -framework OpenGL -framework Appkit

INCLUDE = -I includes

INCLUDE_MLX = -I mlx
LINK_MLX = -L mlx -lmlx
MLX = $(INCLUDE_MLX) $(LINK_MLX)

INCLUDE_LIBFT = -I libft/includes
LINK_LIBFT = -L libft/ -lft
LIBFT = $(INCLUDE_LIBFT) $(LINK_LIBFT)

all: $(NAME)

libft.a:
	make -C libft re

mlx.a:
	make -C mlx re

$(NAME): libft.a mlx.a
	$(CC) $(CFLAGS) $(MLX) $(LIBFT) $(INCLUDE) $(FRAMEWORKS) $(SRC) -o $(NAME)

clean:
	make -C libft fclean
	make -C mlx clean

fclean: clean
	rm -rf $(NAME)

re: clean all
