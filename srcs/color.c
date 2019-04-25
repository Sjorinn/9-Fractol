/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:22:00 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/25 11:19:36 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned long	creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int				get_color(t_mlx *data, int i)
{
	double	r;
	double	g;
	double	b;
	double	percent;
	int		color;

	if (i == MAX_ITER + data->iter)
		return (0x000000);
	percent = i * 100 / MAX_ITER;
	if (percent == 0)
		return (0x000000);
	r = 0 + percent * (0 - 0);
	g = 0 + percent * (102 - 0);
	b = 0 + percent * (255 - 0);
	color = (int)creatergb(r, g, b);
	return (color);
}
