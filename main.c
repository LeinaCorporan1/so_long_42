#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft_42/libft.h"
#include "so_long.h"
int extention_check(char **av,char *extention)
{
    int i;
    int j;
    
    i = sizeof(av[1]);
     i = i - 5;
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
    tab = (char *)malloc(sizeof(char ) * 2);
    if (!tab)
        return (NULL);
    buf = (char *)malloc(sizeof(char ) * 2);
    if (!buf)
        return (NULL);
    ret = read(fd, tab, 1);
    tab[ret] = '\0';
    ft_putstr_fd(tab,1);
    while (ret > 0)
    {
        ret = read(fd, buf, 1);
        buf[ret] = '\0';;
        tab = ft_strjoin(tab, buf);
    }
    ft_putstr_fd(tab,1);
    printf("\n");
    final = ft_split(tab,'\n');
    printf("my final\n");
    while (final[i])
    {
        printf("\n---------%d------\n",i);
        ft_putstr_fd(final[i],1);
        i++;
    }
    printf("\nthe size of final = %ld\n",sizeof(final));
    return (final);
}
int check_size(char **done,t_map *check)
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
    printf("size of done [0] = %ld\n",ft_strlen((const char *)done[0]));
    printf("e = %d c = %d p = %d\n",check -> E, check -> C, check -> P);
    return(1);
}
int main(int ac, char **av)
{
    // int i;
    // int j;
    char **done;
    char *extention;
    t_map check;
    check.E = 0;
    check.C = 0;
    check.P = 0;
    (void)ac;
    extention = ".ber";
    if (!extention_check(av,extention))
        printf("Error\n");
    done = create_tab(av);
   if(check_size(done,&check))
        printf("good\n");
    if (check.E == 1)
        printf("good having E\n");
    if (check.C == 1)
        printf("good having C\n");
    if (check.P == 1)
        printf("good having P\n");
    // else
    //     printf("bad\n");
    // printf("ddddoonenee\n");
}