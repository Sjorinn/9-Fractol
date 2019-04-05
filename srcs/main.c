/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:57:21 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/04 16:30:50 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	t_mlx	data;

	if (argc != 2)
		return (int_str("Usage: ./fractol mandelbrot / julia / xxxxxxxxxxxxx"));
	if (!(data.mlx_ptr = mlx_init()))
		return (int_str("error\n"));
	if (!(data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, LONG, "Fractol")))
		return(int_str("error\n"));
	if (!(data.ptr = mlx_new_image(data.mlx_ptr, WIDTH, LONG)))
		return (int_str("error\n"));
	if (!(data.tab = (unsigned int *)mlx_get_data_addr(data->ptr, &(data->bpp),
		&(data->size), &(data->endian))))
		return (int_str("error\n"));
	if (parser(argv[2], &data) == -1)
		return (int_str("error\n"));
	mlx_mouse_hook(data.win_ptr, deal_mouse, &data);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

int		parser(char *fractal, t_mlx *data)
{
	if (fractal == "julia" || fractal == "julia ")
	{
		data->fractal = 1;
		julia(data);
	}
	else if (fractal == "mandelbrot" || fractal == "mandelbrot ")
	{
		data->fractal = 2;
		mandelbrot(data);
	}
	else
		return (-1);
}
