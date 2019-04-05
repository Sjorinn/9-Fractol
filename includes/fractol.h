/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:54:29 by pchambon          #+#    #+#             */
/*   Updated: 2019/04/05 14:24:38 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define LONG 1400
# define WIDTH 2560
# define F_WIDTH 1680

# include "../X-Libft/includes/libft.h"
# include "../MiniLibX/mlx.h"
# include <sys/types.h>
# include <math.h>

typedef	struct	s_mlx
{
	void			*ptr;
	void			*tab;
	void			*mlx_ptr;
	void			*win_ptr;
	int				fractal;
	t_j			j;
}				t_mlx;

typedef struct	s_j
{
	int		i;
	float	a;
	float	ib;
	float	c_a;
	float	c_ib;
	int		max_iter;
}				t_j;
#endif
