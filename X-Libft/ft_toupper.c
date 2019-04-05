/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:13:41 by pchambon          #+#    #+#             */
/*   Updated: 2018/11/15 15:58:37 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_toupper(int c)
{
	if (c < 123 && c > 96)
		return (c - 32);
	return (c);
}
