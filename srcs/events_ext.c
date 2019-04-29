/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_ext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:09:44 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/29 13:43:13 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		deal_highlight(int key, void *param)
{
	t_mlx *data;

	data = (t_mlx *)param;
	if (key == 125)
	{
		if (data->h <= -1)
			return (0);
		if (data->h == 1)
			data->h -= 2;
		else
			data->h--;
	}
	if (key == 126)
	{
		if (data->h >= MAX_ITER + data->iter - 1)
			return (0);
		if (data->h == -1)
			data->h += 2;
		else
			data->h++;
	}
	fractal(data, data->j.j_r, data->j.j_i);
	return (0);
}

int		deal_iter(int key, void *param)
{
	t_mlx *data;

	data = (t_mlx *)param;
	if (key == 69)
	{
		data->iter += 2;
		fractal(data, data->j.j_r, data->j.j_i);
	}
	if (key == 78)
	{
		data->iter -= 2;
		fractal(data, data->j.j_r, data->j.j_i);
	}
	return (1);
}

int		deal_move(int key, void *param)
{
	t_mlx *data;

	data = (t_mlx *)param;
	if (key == 13)
		data->j.move_y += 0.012 / data->j.zoom;
	if (key == 0)
		data->j.move_x += 0.012 / data->j.zoom;
	if (key == 1)
		data->j.move_y -= 0.012 / data->j.zoom;
	if (key == 2)
		data->j.move_x -= 0.012 / data->j.zoom;
	fractal(data, data->j.j_r, data->j.j_i);
	return (0);
}

int		deal_zoom(int key, int x, int y, void *param)
{
	t_mlx *data;

	data = (t_mlx *)param;
	if (key == 4)
		data->j.zoom *= 1.1;
	if (key == 5)
		data->j.zoom /= 1.1;
	fractal(data, data->j.j_r, data->j.j_i);
	return (1);
}

int		deal_motion(int x, int y, void *param)
{
	t_mlx *data;

	data = (t_mlx *)param;
	if (x < 0 || x >= F_WIDTH || y < 0 || y >= LONG || \
		data->j.s == -1 || data->fractal != 1 || \
		(data->j.j_r != -0.8 && data->j.j_i != 0.156))
		return (0);
	data->j.motion_x = x;
	data->j.motion_y = y;
	fractal(data, data->j.j_r, data->j.j_i);
	return (0);
}
