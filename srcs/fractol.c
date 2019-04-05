/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:48:47 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/05 15:06:29 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia()
  //each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel
  double cRe, cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
  double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
  double zoom = 1, moveX = 0, moveY = 0; //you can change these to zoom and change position
  ColorRGB color; //the RGB color value for the pixel
  int maxIterations = 300; //after how much iterations the function should stop

  //pick some values for the constant c, this determines the shape of the Julia Set
  cRe = -0.7;
  cIm = 0.27015;

  //loop through every pixel
  for(int y = 0; y < LONG; y++)
  for(int x = 0; x < F_WIDTH; x++)
  {
    //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
    newRe = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
    newIm = (y - h / 2) / (0.5 * zoom * h) + moveY;
    int i;
    for(i = 0; i < maxIterations; i++)
    {
      oldRe = newRe;
      oldIm = newIm;
      newRe = oldRe * oldRe - oldIm * oldIm + cRe;
      newIm = 2 * oldRe * oldIm + cIm;
      //if the point is outside the circle with radius 2: stop
      if((newRe * newRe + newIm * newIm) > 4) break;
    }
    //use color model conversion to get rainbow palette, make brightness black if maxIterations reached
    color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
    //draw the pixel
    pset(x, y, color);
  }
/*void		j(t_mlx *d)
{
	int i;
	int j;
	int k;

	i = -1;
	d->j.a = -2;
	d->j.c_a = 0.3;
	d->j.c_ib = 0.5;
	while (i < F_WIDTH)
	{
		d->j.ib = -1;
		while (j < LONG)
		{
				d->j.i = 0;
			while (++i < 50)
			{
				d->j.a = (d->j.a * d->j.a) - (d->j.ib * d->j.ib) + d->j.c_a;
				d->j.ib = (d->j.a * d->j.ib) + (d->j.b * d->j.a) + d->j.c_ib;
				if (is_bounded(d->j.a, d->j.ib) == -1)
				{
					d->j.i = i;
					break ;
				}
			}
			d->j.ib += 0.0017;
		}
		d->j.a += 0.0014
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->ptr, 0, 0);
}*//

void		mandelbrot(t_mlx *d)
{
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->ptr, 0, 0);
}

int			is_bounded(int a; int ib)

