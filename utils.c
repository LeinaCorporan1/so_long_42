/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:24:56 by lcorpora          #+#    #+#             */
/*   Updated: 2022/06/10 18:24:58 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_coins(char **tab)
{
    int i;
    int j;
    int coins;

    i = 0;
    coins = 0;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if (tab[i][j] == 'C')
                coins ++;
            j++;
        }
        i++;
    }
    return (coins);
}

int	extend(char ** tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_free(char **data)
{
	size_t	i;

	i = 0;
	while (data[i])
	{
		
		free(data[i]);
		i++;
	}
	free(data);
	data = NULL;
	return ;
}

char	*ft_strjoin_sl(char *s1, char const *s2)
{
	size_t	j;
	char	*res;
    int i;

    i = 0;
	if (!s1 || !s2)
		return (0);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
    res = ft_memcpy(res, s1, ft_strlen(s1) + 1);
    j = ft_strlen(res);
	while (s2[i])
	{
		res[j] = s2[i];
		i++;
		j++;
	}
    free(s1);
	res[j] = '\0';
	return (res);
}
