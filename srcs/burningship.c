/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 09:49:05 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/25 16:08:41 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	burningship(t_mlx *data, int zoom, int x, int y)
{
	int i;

	i = 0;
	while (++x < F_WIDTH)
	{
		y = -1;
		while (++y < LONG)
		{
			while (i < MAX_ITER)
			{
				i++;
			}
		}
	}
}
