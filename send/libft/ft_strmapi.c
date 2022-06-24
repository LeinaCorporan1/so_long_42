/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:24:40 by lcorpora          #+#    #+#             */
/*   Updated: 2021/12/21 15:17:52 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdlib.h>

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*dest;
	size_t	i;
	char	*convert;

	i = 0;
	if (!s)
		return (NULL);
	convert = (char *)s;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (i < ft_strlen(s))
	{
		dest[i] = (*f)((unsigned int)i, convert[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
