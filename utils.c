#include "so_long.h"

void    init_img(t_map *map)
{
    map -> img.wall = mlx_xpm_file_to_image(map -> mlx, WALL, &map->img.width, &map->img.height);
    map -> img.coin = mlx_xpm_file_to_image(map -> mlx, COIN, &map->img.width, &map->img.height);
    map -> img.exit = mlx_xpm_file_to_image(map -> mlx, EXIT, &map->img.width, &map->img.height);
    map -> img.player = mlx_xpm_file_to_image(map -> mlx, PLAYER, &map->img.width, &map->img.height);
    map -> img.tiles = mlx_xpm_file_to_image(map -> mlx, TILES, &map->img.width, &map->img.height);
}

int    init_map (t_map *map, int ac, char **av)
{
    map -> img.height = SIZE;
    map -> img.width = SIZE;
    map -> movement = 0;
    map -> p_i = 0;
    map -> p_j = 0;
    map -> data = parsing(ac,av);
	if (map -> data == NULL)
		return (0);
    init_img(map);
    return (1);
}
