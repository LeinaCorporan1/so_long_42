/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:44:46 by lcorpora          #+#    #+#             */
/*   Updated: 2021/12/16 17:44:43 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	j;
	char	*res;

	j = 0;
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (*s1)
	{
		res[j] = *s1;
		s1++;
		j++;
	}
	while (*s2)
	{
		res[j] = *s2;
		s2++;
		j++;
	}
	res[j] = '\0';
	return (res);
}
