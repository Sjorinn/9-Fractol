/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:54:50 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/25 16:06:19 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_mlx *data, int i, int x, int y)
{
	int a;
	int ib;

	a = 0;
	ib = 0;
	while (y < LONG)
	{
		x = -1;
		while (x < F_WIDTH)
		{
			while (i < MAX_ITER)
			{
				i++;
			}
			x += PAS;
		}
		y += PAS;
	}
}

void	mandelbrot_init(t_mlx *data)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	mandelbrot(data, i, x, y);
}
