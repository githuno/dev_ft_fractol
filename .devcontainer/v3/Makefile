# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: runoki <runoki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 23:05:32 by runoki            #+#    #+#              #
#    Updated: 2023/12/08 23:10:14 by runoki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
	events.c\
	fractals.c\
	ft_fractol.c\
	maths.c\
	rendering.c

OBJS = $(SRCS:.c=.o)

INC_PATH = .
INC = fractol.h
INCS = $(addprefix $(INC_PATH)/, $(INC))

LIB_PATH = libft
LIB = libft.a
LIBS = $(addprefix $(LIB_PATH)/, $(LIB))

MLX = mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBS) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(MLX) -I$(INC_PATH) -lXext -lX11
#	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(MLX) -framework OpenGL -framework AppKit -I$(INC)

$(LIBS):
	make -C $(LIB_PATH)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)

norm:
	norminette $(SRCS) $(INCS) $(LIB_PATH)/*.c $(LIB_PATH)/*.h
jul:
	./fractol julia
man:
	./fractol mandelbrot
tri:
	./fractol mandelbar

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all norm jul man tri clean fclean re
