#include "so_long.h"

int    init_img(t_map *map)
{
    map -> img.wall = mlx_xpm_file_to_image(map -> mlx, WALL,
     &map->img.width, &map->img.height);
    map -> img.coin = mlx_xpm_file_to_image(map -> mlx, COIN,
     &map->img.width, &map->img.height);
    map -> img.exit = mlx_xpm_file_to_image(map -> mlx, EXIT,
     &map->img.width, &map->img.height);
    map -> img.player = mlx_xpm_file_to_image(map -> mlx, PLAYER,
     &map->img.width, &map->img.height);
    map -> img.tiles = mlx_xpm_file_to_image(map -> mlx, TILES,
     &map->img.width, &map->img.height);
    if (!map -> img.wall || !map -> img.coin || !map -> img.exit ||
     !map -> img.player || !map -> img.tiles)
        return (0);
    return (1);
}

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

int    init_map (t_map *map)
{
    map -> img.height = SIZE;
    map -> img.width = SIZE;
    map -> movement = 0;
    map -> p_i = 0;
    map -> p_j = 0;
    map -> coins = 0;
    map -> total_coins = count_coins(map -> data);                            
	if (!init_img(map)) /*put msg of no img here*/
        return (0);
    return (1);
}
