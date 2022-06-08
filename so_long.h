#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include "mlx_linux/mlx.h"
#include "../libft_42/libft.h"


# define PLAYER "imageso/player.xpm"
# define COIN "imageso/coin.xpm"
# define EXIT "imageso/exit.xpm"
# define TILES "imageso/tiles.xpm"
# define WALL "imageso/wall.xpm"
# define SIZE 32
# define EXTENSION  ".ber"
typedef struct s_asset
{
    int E;
    int C;
    int P;
} t_asset;

typedef struct s_img
{
    void    *wall;
    void    *player;
    void    *tiles;
    void    *coin;
    void    *exit;
    int     height;
    int     width;
} t_img;

typedef struct s_map
{
    void    *mlx;
    void    *win;
    char    **data;
    int     p_i;
    int     p_j;
    int     movement;
    int     coins;
    int     total_coins;
    t_img   img;

} t_map;

int    init_map (t_map *map, char ** tab);
void    init_img(t_map *map);

int extention_check(char **av,char *extention);
char **create_tab(char **av);
int check_size(char **done,t_asset *check);
int parsing(char **av,t_asset *check);
int	init_window(t_map *map, char **tab);
int	destroy_win(t_map *map);
#endif