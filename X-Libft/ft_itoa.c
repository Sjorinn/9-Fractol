/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:53:18 by pchambon          #+#    #+#             */
/*   Updated: 2018/11/26 15:51:13 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int		ft_negativecheck(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static	long	ft_size(int n)
{
	long	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size++);
}

char			*ft_itoa(int n)
{
	long		l;
	long		len;
	char		*itoa;

	l = n;
	len = ft_size(l);
	if (!(itoa = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	itoa[len] = '\0';
	len--;
	if (l < 0)
		l = -l;
	if (n == 0 && (len--))
		itoa[0] = '0';
	while (len >= 0)
	{
		itoa[len] = ((l % 10) + 48);
		len--;
		l /= 10;
	}
	if (ft_negativecheck(n))
		itoa[0] = '-';
	return (itoa);
}
