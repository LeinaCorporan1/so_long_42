/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:20:16 by lcorpora          #+#    #+#             */
/*   Updated: 2021/12/13 16:17:13 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*res;
	int		len;

	i = 0;
	res = NULL;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (str[i] == (unsigned char)c)
		{
			res = (char *) str + i;
		}
		i++;
	}
	return (res);
}
