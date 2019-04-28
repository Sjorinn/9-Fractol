/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:22:00 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/28 14:54:33 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	deal_color_ext(t_mlx *data, int i)
{
	if (i == 3)
	{
		data->r = 0;
		data->g = 1;
		data->b = 1;
	}
	if (i == 4)
	{
		data->r = 1;
		data->g = 0;
		data->b = 1;
	}
	if (i == 5)
	{
		data->r = 1;
		data->g = 1;
		data->b = 0;
	}
	fractal(data, data->j.j_r, data->j.j_i);
}

void	deal_color(t_mlx *data, int key)
{
	static int i = 0;

	i++;
	if (i >= 6)
		i = 0;
	if (i == 0)
	{
		data->r = 0;
		data->g = 0;
		data->b = 1;
	}
	if (i == 1)
	{
		data->r = 0;
		data->g = 1;
		data->b = 0;
	}
	if (i == 2)
	{
		data->r = 1;
		data->g = 0;
		data->b = 0;
	}
	deal_color_ext(data, i);
}

int		get_color(t_mlx *data, int i)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	color;

	if (i == data->h)
		return (0xFFFFFF);
	if (i == MAX_ITER + data->iter)
		return (0x000000);
	r = i * 255 / (MAX_ITER + data->iter) * data->r;
	g = i * 255 / (MAX_ITER + data->iter) * data->g;
	b = i * 255 / (MAX_ITER + data->iter) * data->b;
	color = (r << 16) + (g << 8) + b;
	return (color);
}
