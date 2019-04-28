/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:56:59 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/28 18:48:16 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		deal_key(int key, void *param)
{
	t_mlx *data;

	data = (t_mlx *)param;
	if (key == 12)
		data->j.s *= -1;
	if (key == 53)
		deal_esc(data, key);
	if (key == 49)
		deal_space(data, key);
	if (key == 48)
		deal_color(data, key);
	if (key == 83 || key == 84 || key == 85)
		deal_fractal(data, key);
	if (key == 18 || key == 19 || key == 20 || key == 21 || key == 23)
		deal_int(data, key);
	if (key == 126 || key == 125)
		mlx_hook(data->win_ptr, 2, (1L << 0), deal_highlight, (void *)data);
	if (key == 69 || key == 78)
		mlx_hook(data->win_ptr, 2, (1L << 0), deal_iter, (void *)data);
	if (key == 13 || key == 0 || key == 1 || key == 2)
		mlx_hook(data->win_ptr, 2, (1L << 0), deal_move, (void *)data);
	return (0);
}

void	deal_esc(t_mlx *data, int key)
{
	data = NULL;
	exit(0);
}

void	deal_space(t_mlx *data, int key)
{
	data->h = -1;
	data->iter = 0;
	data->j.zoom = 1;
	data->j.move_x = 0;
	data->j.move_y = 0;
	data->j.motion_x = 0;
	data->j.motion_y = 0;
	fractal(data, data->j.j_r, data->j.j_i);
}

void	deal_fractal(t_mlx *data, int key)
{
	data->h = -1;
	data->iter = 0;
	data->j.zoom = 1;
	data->j.move_x = 0;
	data->j.move_y = 0;
	data->j.motion_x = 0;
	data->j.motion_y = 0;
	if (key == 83 && data->fractal != 1)
		julia_init(data, -0.8, 0.156);
	if (key == 84 && data->fractal != 2)
		mandelbrot_init(data);
	if (key == 85 && data->fractal != 3)
		mandelbar_init(data);
}

void	deal_int(t_mlx *data, int key)
{
	if (data->fractal != 1)
		return ;
	data->j.zoom = 1;
	data->j.move_x = 0;
	data->j.move_y = 0;
	data->j.motion_x = 0;
	data->j.motion_y = 0;
	if (key == 18)
		fractal(data, -0.8, 0.156);
	if (key == 19)
		fractal(data, -0.4, 0.6);
	if (key == 20)
		fractal(data, -1.476, 0);
	if (key == 21)
		fractal(data, 0.285, 0.01);
	if (key == 23)
		fractal(data, 0.3, 0.5);
}
