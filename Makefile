# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 11:30:42 by jpoulvel          #+#    #+#              #
#    Updated: 2019/04/28 18:39:31 by pchambon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIB_DIR = X-Libft
MLX_DIR = MiniLibX
SRCS = srcs/main.c \
		srcs/julia.c \
		srcs/mandelbrot.c \
		srcs/mandelbar.c \
		srcs/hud.c \
		srcs/events.c \
		srcs/events_ext.c \
		srcs/color.c
INCL =$(LIB_DIR)/libft.a \
		$(MLX_DIR)/libmlx.a
OBJ = $(SRCS:.c=.o)
FRMWRK = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror -I $(FRMWRK) $(INCL)

all: LIB $(NAME)

LIB:
	@cd $(LIB_DIR) ; $(MAKE) -f Makefile
	@cd $(MLX_DIR) ; $(MAKE) -f Makefile

$(NAME): LIB $(OBJ)
	@gcc $(FLAGS) $(LIB) -o fractol $(OBJ)

clean: 
	rm -f $(OBJ)
	cd $(LIB_DIR) ; $(MAKE) clean
	cd $(MLX_DIR) ; $(MAKE) clean

fclean: clean
	rm -f a.out $(NAME)
	cd $(LIB_DIR) ; $(MAKE) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re

.SILENT:
