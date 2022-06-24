/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:02:02 by lcorpora          #+#    #+#             */
/*   Updated: 2022/01/07 15:15:42 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char	*str1, const char	*str2, size_t c)
{
	size_t				i;

	i = 0;
	while ((str1[i] || str2[i]) && i < c)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char) str2[i]);
		i++;
	}
	return (0);
}
