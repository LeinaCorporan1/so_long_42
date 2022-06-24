/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:24:07 by lcorpora          #+#    #+#             */
/*   Updated: 2021/12/21 17:11:55 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdlib.h>

int	ft_intlen(long n)
{
	long	count;

	if (n < 0)
	{
		count = 2;
		n = n * (-1);
	}
	else
	{
		count = 1;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*turn_to_char(long nbr, long size, char *dst)
{
	while (nbr > 0 && size >= 0)
	{
		if (dst[size] == '-')
			size--;
		else
			dst[size] = nbr % 10 + '0';
		nbr = nbr / 10;
		size--;
	}
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*dest;
	long	len;
	long	nb;

	nb = n;
	len = ft_intlen(nb);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	if (nb < 0)
	{
		nb = nb * (-1);
		dest[0] = '-';
	}
	dest[len] = '\0';
	len = len - 1;
	if (nb == 0)
		dest[len] = nb + '0';
	else
		dest = turn_to_char(nb, len, dest);
	return (dest);
}
