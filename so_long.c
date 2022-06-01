#include "so_long.h"

int	init_window(t_map *map)
{
	map -> mlx = mlx_init();
	if (map -> mlx == NULL)
		return (0);
	map -> win = mlx_new_window(map->mlx, 1920, 1080, "Hey Molly!");
	if (map->win == NULL)
		return (0);
	return (1);
}

void import_img(t_map *map, int i, int j)
{
	if (map -> data[i][j] == '1')
	mlx_put_image_to_window(map -> mlx, map -> win, map ->img.wall, j * SIZE, i * SIZE);
	if (map -> data[i][j] == '0')
	mlx_put_image_to_window(map -> mlx, map -> win, map ->img.tiles, j * SIZE, i * SIZE);
	if (map -> data[i][j] == 'P')
	{
		map -> p_i = i;
		map -> p_j = j;
		mlx_put_image_to_window(map -> mlx, map -> win, map ->img.player, j * SIZE, i * SIZE);
	}

	if (map -> data[i][j] == 'C')
	mlx_put_image_to_window(map -> mlx, map -> win, map ->img.coin, j * SIZE, i * SIZE);
	if (map -> data[i][j] == 'E')
	mlx_put_image_to_window(map -> mlx, map -> win, map ->img.exit, j * SIZE, i * SIZE);
}

int create_map(t_map *map)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	// map -> data = parsing(ac,av);
	// if (map -> data == NULL)
	// 	return (0);
	while (map -> data[i])
	{
		j = 0;
		while (map -> data[i][j])
		{
			import_img(map,i,j);
			j++;
		}
		i++;
	}
	return (1);
}
int	key_hook(int key_code,t_map *map)
{
	char	c;

	if (key_code == 97 || key_code == 65361)
	{
		c = map -> data[map->p_i][map->p_j];
		map -> data[map->p_i][map->p_j] = map -> data[map->p_i][map->p_j-1];
		map -> data[map->p_i][map->p_j-1] = c;
		
	}
	if (key_code == 100 || key_code == 65363)
	{
		c = map -> data[map->p_i][map->p_j];
		map -> data[map->p_i][map->p_j] = map -> data[map->p_i][map->p_j + 1];
		map -> data[map->p_i][map->p_j + 1] = c;
		
	}
	if (key_code == 119 || key_code == 65362)
	{
		c = map -> data[map->p_i][map->p_j];
		map -> data[map->p_i][map->p_j] = map -> data[map->p_i - 1][map->p_j];
		map -> data[map->p_i - 1][map->p_j] = c;
		
	}
	if (key_code == 115 || key_code == 65364)
	{
		c = map -> data[map->p_i][map->p_j];
		map -> data[map->p_i][map->p_j] = map -> data[map->p_i + 1][map->p_j];
		map -> data[map->p_i + 1][map->p_j] = c;
		
	}
	else
		printf("%d Hello from key_hook!\n", key_code);
	create_map(map);
	return (0);
}
int	main(int ac, char **av)
{
	t_map map;

	if (!init_window(&map))
		return (0);
	init_map(&map,ac,av);
	create_map(&map);
	
	 mlx_key_hook(map.win,&key_hook,&map);
	//  mlx_loop_hook(map.mlx,&create_map,&map);
	mlx_loop(map.mlx);
		
	// try = mlx_xpm_file_to_image(mlx,PLAYER,48,48);
	// mlx_put_image_to_window(mlx,win,)
	
}
