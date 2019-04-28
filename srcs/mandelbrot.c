/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:54:50 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/28 18:30:21 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_mlx *d)
{
	double	tab[6];

	while (++d->j.y <= d->j.y_max)
	{
		d->j.x = -1;
		while (++d->j.x < F_WIDTH)
		{
			d->j.iter = -1;
			tab[1] = 0;
			tab[2] = 0;
			tab[4] = (d->j.y - LONG / 2) \
				/ (0.5 * d->j.zoom * LONG) + d->j.move_y;
			tab[3] = 1.5 * (d->j.x - 2 * F_WIDTH / 3) \
				/ (0.6 * d->j.zoom * F_WIDTH) + d->j.move_x;
			while (++d->j.iter < MAX_ITER + d->iter \
				&& tab[1] * tab[1] + tab[2] * tab[2] <= 4)
			{
				tab[5] = tab[1] * tab[1] - tab[2] * tab[2] + tab[3];
				tab[2] = 2 * tab[1] * tab[2] + tab[4];
				tab[1] = tab[5];
			}
			d->tab[(d->j.y * F_WIDTH) + d->j.x] = get_color(d, d->j.iter);
		}
	}
}

void	*mandelbrot_convert(void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	mandelbrot(data);
	return (NULL);
}

void	mandelbrot_init(t_mlx *d)
{
	t_mlx		tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	d->j.x = 0;
	d->j.y = -1;
	d->j.iter = 0;
	d->fractal = 2;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)d, sizeof(t_mlx));
		tab[i].j.y = THREAD_WIDTH * i;
		tab[i].j.y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, mandelbrot_convert, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->ptr, 0, 0);
}
