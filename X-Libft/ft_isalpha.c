/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:47:29 by pchambon          #+#    #+#             */
/*   Updated: 2018/11/15 15:52:21 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_isalpha(int c)
{
	if ((c < 91 && c > 64) || (c < 123 && c > 96))
		return (1);
	return (0);
}
