/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:57:21 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/25 16:04:51 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	t_mlx	data;

	if (argc != 2)
		return (int_str("Usage: ./fractol julia / mandelbrot / burningship"));
	if (!(data.mlx_ptr = mlx_init()))
		return (int_str("error\n"));
	if (!(data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, LONG, "Fractol")))
		return (int_str("error\n"));
	if (!(data.ptr = mlx_new_image(data.mlx_ptr, F_WIDTH, LONG)))
		return (int_str("error\n"));
	if (!(data.tab = (unsigned int *)mlx_get_data_addr(data.ptr, &(data.bpp),
		&(data.size), &(data.endian))))
		return (int_str("error\n"));
	if (parser(argv[1], &data) == -1)
		return (int_str("error\n"));
	init_hud(&data);
	julia_init(&data, -0.8, 0.156);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_mouse_hook(data.win_ptr, deal_mouse, &data);
	mlx_hook(data.win_ptr, 6, (1L < 66), deal_motion, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

int		parser(char *fractal, t_mlx *data)
{
	if (!(strcmp(fractal, "julia")))
		julia_init(data, -0.8, 0.156);
	else if (!(strcmp(fractal, "mandelbrot")))
		mandelbrot_init(data);
	else if (!(strcmp(fractal, "burningship")))
		julia_init(data, -0.8, 0.156);
	else
		return (-1);
	return (0);
}
