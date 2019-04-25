/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:56:59 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/25 16:07:23 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	deal_fractal(t_mlx *data, int key)
{
	if (key == 83)
		julia_init(data, -0.8, 0.156);
	if (key == 84)
		mandelbrot(data, 1, 0, 0);
	if (key == 85)
		burningship(data, 1, 0, 0);
}

void	deal_int(t_mlx *data, int key)
{
	if (key == 18)
		julia_init(data, -0.8, 0.156);
	if (key == 19)
		julia_init(data, -0.4, 0.6);
	if (key == 20)
		julia_init(data, -1.476, 0);
	if (key == 21)
		julia_init(data, 0.285, 0.01);
	if (key == 23)
		julia_init(data, 0.3, 0.5);
}

int		deal_move(int key, void *param)
{
	t_mlx *data;

	data = (t_mlx *)param;
	if (key == 13)
		data->j.move_y += 0.006;
	if (key == 0)
		data->j.move_x += 0.006;
	if (key == 1)
		data->j.move_y -= 0.006;
	if (key == 2)
		data->j.move_x -= 0.006;
	julia(data, 0, 0, 0);
	return (0);
}

void	deal_esc(t_mlx *data, int key)
{
	data = NULL;
	exit(0);
}

int		deal_key(int key, void *param)
{
	t_mlx *data;

	printf("%d\n", key);
	data = (t_mlx *)param;
	if (key == 69 || key == 78)
		mlx_hook(data->win_ptr, 2, (1L << 0), deal_iter, (void *)data);
	if (key == 53)
		deal_esc(data, key);
	if (key == 49)
		deal_space(data, key);
	if (key == 83 || key == 84 || key == 85)
		deal_fractal(data, key);
	if (key == 18 || key == 19 || key == 20 || key == 21 || key == 23)
		deal_int(data, key);
	if (key == 13 || key == 0 || key == 1 || key == 2)
		mlx_hook(data->win_ptr, 2, (1L << 0), deal_move, (void *)data);
	if (key == 12)
		data->stop = data->stop * -1;
	return (0);
}
