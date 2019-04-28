/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 09:37:00 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/28 17:52:06 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_hud_ext(t_mlx *d)
{
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1015, 300, 0xFFFFFF, "CONTROLS");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 350, \
		0xFFFFFF, "Fractals : 1 / 2 / 3 (pad)");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 375, \
		0xFFFFFF, "Interesting Julia : 1 / 2 / 3 / 4 / 5");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 400, \
		0xFFFFFF, "Highlight iteration : UP / DOWN");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 425, \
		0xFFFFFF, "unlock / lock mouse moving : Q");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 450, \
		0xFFFFFF, "Move mouse to change params (julia only)");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 475, 0xFFFFFF, "Move : WASD");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 500, 0xFFFFFF,
		"Zoom : Scroll Up");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 525, 0xFFFFFF,
		"Dezoom : Scroll Down");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 550, 0xFFFFFF,
		"Change precision : + / - (pad)");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 575, \
		0xFFFFFF, "Change color : Tab");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 600, \
		0xFFFFFF, "Reset : Space");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 625, \
		0xFFFFFF, "Quit : Escape");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1150, 650, 0xFFFFFF, "by pchambon");
}

void	init_hud(t_mlx *d)
{
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1015, 25, 0xFFFFFF, "Fractals");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 850, 62, 0xFFFFFF, "1) Julia");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 975, 62, 0xFFFFFF, "2) Mandelbrot");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1125, 62, \
		0xFFFFFF, "3) Mandelbar");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 875, 125, \
		0xFFFFFF, "Interesting Configurations (Julia Only)");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 900, 185, \
		0xFFFFFF, "1/ −0,8 + 0,156i");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1100, 185, \
		0xFFFFFF, "2/ −0,4 + 0,6i");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 900, 210, 0xFFFFFF, "3/ -1,476");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1100, 210, \
		0xFFFFFF, "4/ 0,285 + 0,01i");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1000, 245, \
		0xFFFFFF, "5/ 0,3 + 0,5i");
	init_hud_ext(d);
}
