#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

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

void move(t_map *map, int map_i, int map_j)
{
	char c;
	
	c = map -> data[map->p_i][map->p_j];
	if (map -> data[map_i][map_j] == 'C')
		map -> coins += 1;
	map -> data[map->p_i][map->p_j] = '0';
	map -> data[map_i][map_j] = c;
}

int	check_move(t_map *map, int map_i, int map_j)
{
	if (map -> data [map_i][map_j] == '1')
		return (0);
	if (map -> data [map_i][map_j] == 'E' && map -> coins != map -> total_coins)
		return (0);
	return (1);
}

void	destroy_image(t_map *map)
{
	mlx_destroy_image(map -> mlx, map -> img.wall);
	mlx_destroy_image(map -> mlx, map -> img.player);
	mlx_destroy_image(map -> mlx, map -> img.coin);
	mlx_destroy_image(map -> mlx, map -> img.exit);
	mlx_destroy_image(map -> mlx, map -> img.tiles);
}

int	key_hook(int key_code,t_map *map)
{

	int map_i;
	int map_j;

	map_i = map -> p_i;
	map_j = map -> p_j;
	if (key_code == 65307)
	{
		destroy_image(map);
		mlx_clear_window(map -> mlx, map -> win);
		mlx_destroy_window(map -> mlx, map -> win);
		mlx_destroy_display(map -> mlx);
		map -> mlx = NULL;
		free(map->mlx);
		exit(0);
		// ft_free(map->data);
		return (0);
	}
	if (key_code == 97 || key_code == 65361) /*'a' move left*/
		map_j--;
	if (key_code == 100 || key_code == 65363) /*'d' move right*/
		map_j++;
	if (key_code == 119 || key_code == 65362) /*'w' move top*/
		map_i--;
	if (key_code == 115 || key_code == 65364) /*'s' move bottom*/
		map_i++;
	if (check_move(map, map_i, map_j))
		move(map, map_i, map_j);
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
	mlx_loop(map.mlx);
	// destroy_image(&map);
	printf("sortie loop\n");
	// free(map.mlx);
	ft_free(map.data);
	return (0);
}