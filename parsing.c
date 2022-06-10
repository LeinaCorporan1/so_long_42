#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft_42/libft.h"
#include "so_long.h"


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

int extention_check(char **av,char *extention)
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

char *insert_tab(char *tab, char *buf, int ret, int fd)
{
    if (ret <= 0)
        free(buf);
    while (ret > 0)
    {
        if (tab == NULL)
            tab = ft_strdup(buf);
        else
        {
            if (buf[0] == '\n' && tab[ft_strlen(tab) - 1] == '\n')
            {
                free(buf);
                free(tab);
                return (NULL);
            }
            tab = ft_strjoin_sl(tab, buf);
        }    
        ret = read(fd, buf, 1);
        if (ret >= 0)
            buf[ret] = '\0';
    }
    return (tab);
}

char **create_tab(char **av, char **final)
{
    char *tab;
    char *buf; 
    int ret;
    int fd;

    tab = NULL; 
    fd  = open(av[1], O_RDONLY); 
	if (fd == -1) /* line to erase*/
        return (NULL);/* line to erase*/
    buf = (char *)malloc(sizeof(char ) * 2);
    if (!buf)  /*add fd protection here*/
        return (NULL);
    ret = read(fd, buf, 1);
    if (ret >= 0)
        buf[ret] = '\0';
    tab = insert_tab(tab, buf, ret, fd);
    if (tab == NULL)
    {
        free(tab);
        return (NULL);
    }
    ft_putstr_fd(tab,1); /* line to erase*/
    printf("\n"); /* line to erase*/
    final = ft_split(tab,'\n');
    free(buf);
    free(tab);
    return (final);
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
            return (0);
        i++;
    }
    i--;
    k  = 0;
    while (tab[i][k] && tab[0][k])
    {
        if (tab[i][k] != '1' || tab[0][k] != '1')
            return (0);
        k++;
    }
    tab = check_asset(tab, check, i, k);
    if (check -> E != 1 || check -> C != 1 ||
     check -> P != 1 || check -> LINE != 1)
        return(0);
return(1);
}

// int parsing(char **av, t_asset *check)
// {
//     check -> E = 0;
//     check -> C = 0;
//     check -> P = 0;
//     check -> LINE = 1;
//     if (!extention_check(av,EXTENSION))
//      {
//          printf("Error\n");
//          return(0);
//      }     
//     return(1);
// }