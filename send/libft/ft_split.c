/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:24:11 by lcorpora          #+#    #+#             */
/*   Updated: 2022/01/07 14:47:00 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdlib.h>

static int	ft_count(char const *str, char v)
{
	int	f;
	int	s;

	f = 0;
	s = 0;
	if (str[0] != v)
		f = 1;
	while (str[s])
	{
		if (str[s] == v && str[s + 1] != v && str[s + 1] != '\0')
			f++;
		s++;
	}
	return (f);
}

static int	ft_word(int a, char const *sent, char h)
{
	int	d;

	d = 0;
	while (sent[a] && sent[a] != h)
	{
		d++;
		a++;
	}
	return (d);
}

static char	*ft_add(int x, const char *src, char *dest, int y)
{
	int		i;
	int		t;

	i = 0;
	t = y + x;
	while (x < t)
	{
		dest[i] = src[x];
		i++;
		x++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_free(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	j = 0;
	i = -1;
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[++i] && j < ft_count(s, c))
	{
		if (s[i] != c)
		{
			res[j] = malloc(sizeof(char) * (1 + ft_word(i, s, c)));
			if (!res[j])
				return (ft_free(res));
			res[j] = ft_add(i, s, res[j], ft_word(i, s, c));
			i += ft_word(i, s, c) - 1;
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}
