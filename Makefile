# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 11:30:42 by jpoulvel          #+#    #+#              #
#    Updated: 2019/04/25 11:22:12 by pchambon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = srcs/main.c \
		srcs/julia.c \
		srcs/mandelbrot.c \
		srcs/burningship.c \
		srcs/hud.c \
		srcs/events.c \
		srcs/events_ext.c \
		srcs/color.c

OBJ = $(SRCS:.c=.o)

LIB_DIR = X-Libft
MLX_DIR = MiniLibX

INCL =$(LIB_DIR)/libft.a \
		$(MLX_DIR)/libmlx.a \

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

aya: re
	make clean
	./fractol julia

.PHONY: all clean fclean re

.SILENT:
