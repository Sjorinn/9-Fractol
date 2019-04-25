/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 09:37:00 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/25 16:09:29 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_hud_ext(t_mlx *d)
{
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1015, 325, 0xFFFFFF, "CONTROLS");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 375,
		0xFFFFFF, "Fractals : 1 / 2 / 3 (pad)");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 400, 0xFFFFFF, "Move : WASD");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 425, 0xFFFFFF,
		"Zoom : Scroll Up");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 450, 0xFFFFFF,
		"Dezoom : Scroll Down");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 500,
		0xFFFFFF, "Interesting Fractals : 1 / 2 / 3 / 4");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 525,
		0xFFFFFF, "Move mouse to change params (julia only)");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 550,
		0xFFFFFF, "Lock params : right Shift");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 575,
		0xFFFFFF, "Quit : Escape");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 600,
		0xFFFFFF, "Reset : Space");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1150, 650, 0xFFFFFF, "by pchambon");
}

void	init_hud(t_mlx *d)
{
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1015, 25, 0xFFFFFF, "Fractals");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 62, 0xFFFFFF, "Julia");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1000, 62, 0xFFFFFF, "Mandelbrot");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1150, 62, 0xFFFFFF, "Mandelbrat");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 875, 175,
		0xFFFFFF, "Interesting Configurations (Julia Only)");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 900, 235,
		0xFFFFFF, "1/ −0,8 + 0,156i");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1100, 235,
		0xFFFFFF, "2/ −0,4 + 0,6i");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 900, 260, 0xFFFFFF, "3/ -1,476");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1100, 260,
		0xFFFFFF, "4/ 0,285 + 0,01i");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1000, 285,
		0xFFFFFF, "5/ 0,3 + 0,5i");
	init_hud_ext(d);
}
