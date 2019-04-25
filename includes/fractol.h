/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:54:29 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/25 15:53:29 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define LONG 700
# define WIDTH 1280
# define F_WIDTH 840
# define MAX_ITER 100
# define PAS 1

# include "../X-Libft/includes/libft.h"
# include "../MiniLibX/mlx.h"
# include "stdio.h"
# include <sys/types.h>
# include <math.h>

typedef struct	s_julia
{
	double			R;
	double			I;
	double			c_R;
	double			c_I;
	double			zoom;
	double			tmp_R;
	double			tmp_I;
	double			move_x;
	double			move_y;
}				t_julia;

typedef	struct	s_mlx
{
	int				bpp;
	int				size;
	int				iter;
	int				stop;
	int				endian;
	int				fractal;
	void			*ptr;
	void			*mlx_ptr;
	void			*win_ptr;
	t_julia			j;
	unsigned int	*tab;
}				t_mlx;

int				main(int argc, char **argv);
int				parser(char *fractal, t_mlx *data);
void			julia_init(t_mlx *data, double c_r, double c_i);
void			julia(t_mlx *data, int x, int y, int i);
void			mandelbrot_init(t_mlx *data);
void			mandelbrot(t_mlx *data, int i, int x, int y);
void			burningship(t_mlx *data, int zoom, int x, int y);
void			init_hud_ext(t_mlx *d);
void			init_hud(t_mlx *data);
int				deal_mouse(int key, int x, int y, void *param);
int				deal_motion(int x, int y, void *param);
int				deal_iter(int key, void *param);
int				deal_move(int key, void *param);
int				deal_key(int key, void *data);
void			deal_fractal(t_mlx *data, int key);
void			deal_space(t_mlx *data, int key);
void			deal_color(t_mlx *data, int key);
void			deal_esc(t_mlx *data, int key);
unsigned long	creatergb(int r, int g, int b);
int				get_color(t_mlx *data, int i);
#endif
