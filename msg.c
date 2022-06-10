#include "so_long.h"

void    error_map(t_asset   *check)
{
    ft_putstr_fd("Error\n", 1);
    if (check -> P == 0)
    ft_putstr_fd ("There is no player in the map !\n", 1);
    if (check -> C == 0)
    ft_putstr_fd ("There is no coin in the map !\n", 1);
    if (check -> E == 0)
    ft_putstr_fd ("There is no exit in the map !\n", 1);
    if (check -> LINE == 0)
    ft_putstr_fd ("The map is missing walls !\n", 1);
    if (check -> RECT == 0)
    ft_putstr_fd ("The map is not a rectangular !\n", 1);
}

void    error_extension(void)
{
    ft_putstr_fd("Error\n", 1);
    ft_putstr_fd ("The map name is not valid !\n", 1);
}

void move_msg(int move)
{
    ft_putstr_fd("move counter = ", 1);
    ft_putnbr_fd(move, 1);
	ft_putstr_fd("\n",1);
}

