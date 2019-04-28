/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:54:29 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/28 18:40:00 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define LONG 700
# define WIDTH 1280
# define F_WIDTH 840
# define MAX_ITER 100
# define THREAD_WIDTH 7
# define THREAD_NUMBER 100

# include "../X-Libft/includes/libft.h"
# include "../MiniLibX/mlx.h"
# include <sys/types.h>
# include <pthread.h>
# include <math.h>

typedef struct	s_julia
{
	int				s;
	int				x;
	int				y;
	int				iter;
	int				y_max;
	double			r;
	double			i;
	double			j_r;
	double			j_i;
	double			c_r;
	double			c_i;
	double			zoom;
	double			tmp_r;
	double			tmp_i;
	double			move_x;
	double			move_y;
	double			motion_x;
	double			motion_y;
}				t_julia;

typedef	struct	s_mlx
{
	t_julia			j;
	float			r;
	float			g;
	float			b;
	int				h;
	int				bpp;
	int				size;
	int				iter;
	int				endian;
	int				fractal;
	unsigned int	*tab;
	void			*ptr;
	void			*mlx_ptr;
	void			*win_ptr;
}				t_mlx;

int				main(int argc, char **argv);
int				parser(char *fractal, t_mlx *data);
void			init_hud(t_mlx *data);
void			init_hud_ext(t_mlx *d);
void			julia_init(t_mlx *data, double c_r, double c_i);
void			julia(t_mlx *data);
void			mandelbrot_init(t_mlx *data);
void			mandelbrot(t_mlx *data);
void			mandelbar_init(t_mlx *data);
void			mandelbar(t_mlx *data);
void			fractal(t_mlx *data, double j_r, double j_i);
int				deal_key(int key, void *data);
void			deal_esc(t_mlx *data, int key);
void			deal_int(t_mlx *data, int key);
int				deal_lock(int key, void *param);
int				deal_iter(int key, void *param);
int				deal_move(int key, void *param);
int				get_color(t_mlx *data, int key);
void			deal_space(t_mlx *data, int key);
void			deal_color(t_mlx *data, int key);
void			deal_fractal(t_mlx *data, int key);
int				deal_highlight(int key, void *param);
int				deal_motion(int x, int y, void *param);
int				deal_zoom(int key, int x, int y, void *param);
#endif
