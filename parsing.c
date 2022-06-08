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
	j = 0;
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[j] = s1[i];
		i++;
		j++;
	}
    // res = ft_strnstr(res,s1,ft_strlen(s1));
    // printf("my char = %s\n",res);
    i = 0;
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
    // printf("my i dans extensioncheck %d\n",i);
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

char **create_tab(char **av)
{
    char *tab;
    char *buf;
    char **final;
    int ret;
    int fd;
    int i;
    
    i = 0;
    fd  = open(av[1], O_RDONLY);
	if (fd == -1)
        return (NULL);
   // tab = (char *)malloc(sizeof(char ) * 2);
   // if (!tab)
     //   return (NULL);


     tab = NULL;
    buf = (char *)malloc(sizeof(char ) * 2);
    if (!buf)
        return (NULL);
    ret = read(fd, buf, 1);
    if (ret >= 0)
        buf[ret] = '\0';
    ft_putstr_fd(tab,1);
    while (ret > 0)
    {
        if (tab == NULL)
            tab = ft_strdup(buf);
        else
            tab = ft_strjoin_sl(tab, buf);
        ret = read(fd, buf, 1);
        if (ret >= 0)
            buf[ret] = '\0';
    }
    ft_putstr_fd(tab,1);
    printf("\n");

    // buf = get_next_line()
    final = ft_split(tab,'\n');
    if (final == NULL)
    {
        // free(tab);
        free(buf);
        return (NULL);
    }
    printf("my final\n");
    while (final[i])
    {
        printf("\n---------%d------\n",i);
        ft_putstr_fd(final[i],1);
        i++;
    }
    printf("\nthe size of final = %ld\n",sizeof(final));
    free(buf);
    free(tab);
    return (final);
}




int check_size(char **done,t_asset *check)
{
    int i;
    int k;
    size_t j;

    i = 1;
    j = ft_strlen((const char *)done[0]);
    while (done[i])
    {
        if (ft_strlen((const char *)done[i]) != j)
            return (0);
        i++;
    }
    i--;
    k  = 0;
    while (done[i][k] && done[0][k])
    {
        if (done[i][k] != '1' || done[0][k] != '1')
            return (0);
        k++;
    }
    i = 0;
    k = 0;
    while (done[i])
    {
        if (done[i][0] != '1' || done[i][j - 1] != '1')
        {
            printf("done[%d][%d] = %c\n",i,0,done[i][0]);
            printf("done[%d][%ld] = %c\n",i,j-1,done[i][j-1]);
            return (0);
        }
        k = 0;
        while (done[i][k])
        {
            if (done[i][k] == 'P' && check -> P == 1)
                done[i][k] = '0';
            if (done[i][k] == 'E')
                check -> E = 1;
            if (done[i][k] == 'C')
                check -> C = 1;
            if (done[i][k] == 'P')
                check -> P = 1;
            k++;
        }
        
        i++;
    }
    i = 0;
    while (done[i][k])
    {

    }
   if (check -> E != 1 && check -> C == 1 && check -> P == 1)
    return(0);
return(1);
}
int parsing(char **av, t_asset *check)
{

    // char **done;
    // char *extention;
    check -> E = 0;
    check -> C = 0;
    check -> P = 0;
    // extention = ".ber";
    if (!extention_check(av,EXTENSION))
     {
         printf("Error\n");
         return(0);
     }   
    // done = create_tab(av);
//    if(!check_size(done,&check))
//    {
//        printf("error size\n");
//        return(NULL);
//    }     
    return(1);
}