/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:57:21 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/28 18:22:33 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	t_mlx	data;

	if (argc != 2)
		return (int_str("Usage: ./fractol julia / mandelbrot / mandelbar"));
	if (!(data.mlx_ptr = mlx_init()))
		return (int_str("error\n"));
	if (!(data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, LONG, "Fractol")))
		return (int_str("error\n"));
	if (!(data.ptr = mlx_new_image(data.mlx_ptr, F_WIDTH, LONG)))
		return (int_str("error\n"));
	if (!(data.tab = (unsigned int *)mlx_get_data_addr(data.ptr, &(data.bpp),
		&(data.size), &(data.endian))))
		return (int_str("error\n"));
	init_hud(&data);
	if (parser(argv[1], &data) == -1)
		return (int_str("Usage: ./fractol julia / mandelbrot / mandelbar"));
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_mouse_hook(data.win_ptr, deal_zoom, &data);
	mlx_hook(data.win_ptr, 6, (1L << 6), deal_motion, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

int		parser(char *fractal, t_mlx *data)
{
	data->r = 0;
	data->g = 0;
	data->b = 1;
	data->h = -1;
	data->iter = 0;
	data->j.s = -1;
	data->j.zoom = 1;
	data->j.j_r = -0.8;
	data->j.j_i = 0.156;
	if (!(strcmp(fractal, "julia")))
		julia_init(data, data->j.j_r, data->j.j_i);
	else if (!(strcmp(fractal, "mandelbrot")))
		mandelbrot_init(data);
	else if (!(strcmp(fractal, "mandelbrat")))
		mandelbar_init(data);
	else
		return (-1);
	return (0);
}

void	fractal(t_mlx *data, double j_r, double j_i)
{
	if (data->fractal == 1)
		julia_init(data, j_r, j_i);
	if (data->fractal == 2)
		mandelbrot_init(data);
	if (data->fractal == 3)
		mandelbar_init(data);
}
