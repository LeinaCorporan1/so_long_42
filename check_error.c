/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:23:36 by lcorpora          #+#    #+#             */
/*   Updated: 2022/06/10 18:23:39 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int extension_check(char **av,char *extention)
{
    int i;
    int j;
    
    j = 0;
    
    i = ft_strlen(av[1]);
     i = i - ft_strlen(extention);
     if (i == 0)
     return (0);
     while (av[1][i])
     {
         if ( av[1][i] != extention[j])
            return (0);
        i++;
        j++;
     }
     return (1);
}

char **check_asset(char **tab,t_asset *check, int i, int k)
{
    i = 0;
    k = 0;
     while (tab[i])
    {
        if (tab[i][0] != '1' || tab[i][ft_strlen(tab[0]) - 1] != '1')
            check -> LINE = 0;
        k = 0;
        while (tab[i][k])
        {
            if (tab[i][k] == 'P' && check -> P == 1)
                tab[i][k] = '0';
            if (tab[i][k] == 'E')
                check -> E = 1;
            if (tab[i][k] == 'C')
                check -> C = 1;
            if (tab[i][k] == 'P')
                check -> P = 1;
            k++;
        }
        i++;
    }
    return (tab);
}

int check_map(char **tab, t_asset *check)
{
    int i;
    int k;
    size_t j;

    i = 1;
    j = ft_strlen((const char *)tab[0]);
    while (tab[i])
    {
        if (ft_strlen((const char *)tab[i]) != j)
            check -> RECT = 0;
        i++;
    }
    i--;
    k  = 0;
    while (tab[i][k] && tab[0][k])
    {
        if (tab[i][k] != '1' || tab[0][k] != '1')
            check -> RECT = 0;
        k++;
    }
    tab = check_asset(tab, check, i, k);
    if (check -> E != 1 || check -> C != 1 ||
     check -> P != 1 || check -> LINE != 1 || check -> RECT != 1)
        return(0);
return(1);
}

int check_error(char **av, t_asset *check, t_map *map)
{
	check -> E = 0;
    check -> C = 0;
    check -> P = 0;
    check -> LINE = 1;
    check -> RECT = 1;
    if (!extension_check(av,EXTENSION))
     {
         error_extension();
         return(0);
     }
	 map -> data = create_tab(av, map -> data);
		if (map -> data == NULL)
        {
            error_extension();
            return (0);
        }
		if(!check_map(map -> data, check))
  	 {
          error_map(check);
	 	  ft_free(map -> data);
       	return(0);
  	 }
	return (1);
}
