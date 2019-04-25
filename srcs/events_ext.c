/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_ext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:09:44 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/25 16:03:59 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	deal_space(t_mlx *data, int key)
{
	data->iter = 0;
	data->j.zoom = 0;
	data->j.move_x = 0;
	data->j.move_y = 0;
	julia_init(data, -0.8, 0.156);
}

int		deal_iter(int key, void *param)
{
	t_mlx *data;

	data = (t_mlx *)param;
	if (key == 69 && data)
	{
		data->iter += 2;
		julia(data, 0, 0, 0);
	}
	if (key == 78)
	{
		data->iter -= 2;
		julia(data, 0, 0, 0);
	}
	return (1);
}

int		deal_mouse(int key, int x, int y, void *param)
{
	t_mlx *data;

	data = (t_mlx *)param;
	if (key == 4)
		data->j.zoom += 0.1;
	if (key == 5)
		data->j.zoom -= 0.1;
	julia(data, 0, 0, 0);
	return (1);
}

int		deal_motion(int x, int y, void *param)
{
	t_mlx *data;

	if (x < 0 || x >= F_WIDTH || y < 0 || y >= LONG || data->stop != 1)
		return (0);
	data = (t_mlx *)param;
	data->j.c_R += ((F_WIDTH / 2) - x) * 0.00001;
	data->j.c_I += ((LONG / 2) - y) * 0.00001;
	julia(data, 0, 0, 0);
	return (0);
}
