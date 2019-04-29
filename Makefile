# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 11:30:42 by jpoulvel          #+#    #+#              #
#    Updated: 2019/04/29 14:50:18 by pchambon         ###   ########.fr        #
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
	@$(MAKE) -C $(LIB_DIR)
	@echo "Compiling Libft : \033[0;32m[OK]\033[0m"
	@$(MAKE) -C $(MLX_DIR)
	@echo "Compiling MiniLibX : \033[0;32m[OK]\033[0m"

$(NAME): LIB $(OBJ)
	@gcc $(FLAGS) $(LIB) -o fractol $(OBJ)
	@echo "Compiling Fractol : \033[0;32m[OK]\033[0m"

clean: 
	@rm -f $(OBJ)
	@echo "Compiling Fractol : \033[0;32m[OK]\033[0m"
	@cd $(LIB_DIR) ; $(MAKE) clean
	@echo "Cleaning Libft : \033[0;32m[OK]\033[0m"
	@cd $(MLX_DIR) ; $(MAKE) clean
	@echo "Cleaning MiniLibX : \033[0;32m[OK]\033[0m"

fclean: clean
	@rm -f a.out $(NAME)
	@cd $(LIB_DIR) ; $(MAKE) fclean
	@echo "Full Cleaning : \033[0;32m[OK]\033[0m"

re: fclean $(NAME)

julia: all clean
	@echo "Launching julia : \033[0;32m[OK]\033[0m"
	@./fractol julia

mandelbrot: all clean
	@echo "Launching mandelbrot : \033[0;32m[OK]\033[0m"
	@./fractol mandelbrot

mandelbar: all clean
	@echo "Launching mandelbar : \033[0;32m[OK]\033[0m"
	@./fractol mandelbar

.PHONY: all clean fclean re julia mandelbrot mandelbar

.SILENT:
