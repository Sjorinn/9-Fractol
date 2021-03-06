/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:48:47 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/28 18:33:17 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

void	julia(t_mlx *d)
{
	while (++d->j.y <= d->j.y_max)
	{
		d->j.x = -1;
		while (++d->j.x < F_WIDTH)
		{
			d->j.iter = -1;
			d->j.i = (d->j.y - LONG / 2) \
				/ (0.5 * d->j.zoom * LONG) + d->j.move_y;
			d->j.r = 1.5 * (d->j.x - F_WIDTH / 2) \
				/ (0.5 * d->j.zoom * F_WIDTH) + d->j.move_x;
			while (++d->j.iter < MAX_ITER + d->iter)
			{
				d->j.tmp_r = d->j.r;
				d->j.tmp_i = d->j.i;
				d->j.r = d->j.tmp_r * d->j.tmp_r - \
					d->j.tmp_i * d->j.tmp_i + d->j.c_r;
				d->j.i = 2 * d->j.tmp_r * d->j.tmp_i + d->j.c_i;
				if ((d->j.r * d->j.r + d->j.i * d->j.i) > 4)
					break ;
			}
			d->tab[(d->j.y * F_WIDTH) + d->j.x] = get_color(d, d->j.iter);
		}
	}
}

void	*julia_convert(void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	julia(data);
	return (NULL);
}

void	julia_init(t_mlx *d, double c_r, double c_i)
{
	t_mlx		tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	d->j.x = 0;
	d->j.y = -1;
	d->j.iter = 0;
	d->fractal = 1;
	d->j.j_r = c_r;
	d->j.j_i = c_i;
	d->j.c_r = c_r + d->j.motion_x / 840;
	d->j.c_i = c_i + d->j.motion_y / 700;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)d, sizeof(t_mlx));
		tab[i].j.y = THREAD_WIDTH * i;
		tab[i].j.y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, julia_convert, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->ptr, 0, 0);
}
