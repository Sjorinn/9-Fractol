/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:48:47 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/25 16:05:56 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

void	julia(t_mlx *data, int x, int y, int i)
{
	while (++y < LONG)
	{
		x = -1;
		while (++x < F_WIDTH)
		{
			i = -1;
			data->j.I = (y - LONG / 2) /
				(0.5 * data->j.zoom * LONG) + data->j.move_y;
			data->j.R = 1.5 * (x - F_WIDTH / 2) /
				(0.5 * data->j.zoom * F_WIDTH) + data->j.move_x;
			while (++i < MAX_ITER + data->iter)
			{
				data->j.tmp_R = data->j.R;
				data->j.tmp_I = data->j.I;
				data->j.R = data->j.tmp_R * data->j.tmp_R -
					data->j.tmp_I * data->j.tmp_I + data->j.c_R;
				data->j.I = 2 * data->j.tmp_R * data->j.tmp_I + data->j.c_I;
				if ((data->j.R * data->j.R + data->j.I * data->j.I) > 4)
					break ;
			}
			data->tab[(y * F_WIDTH + 1) + x] = get_color(data, i);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->ptr, 0, 0);
}

void	julia_init(t_mlx *data, double c_r, double c_i)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = -1;
	data->j.zoom = 1;
	data->j.move_y = 0;
	data->j.move_x = 0;
	data->j.c_R = c_r;
	data->j.c_I = c_i;
	julia(data, x, y, i);
}
