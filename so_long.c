#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	line(char ** tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

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
int	init_window(t_map *map, char ** tab)
{
	map -> mlx = mlx_init();
	if (map -> mlx == NULL)
		return (0);
	map -> win = mlx_new_window(map->mlx,ft_strlen(tab[1]) * 32  + 1, line(tab) * 32 + 1, "Hey Molly!");
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

	map -> movement +=1;
	ft_putnbr_fd(map -> movement, 1);
	ft_putstr_fd("\n",1);
	c = map -> data[map->p_i][map->p_j];
	if (map -> data[map_i][map_j] == 'E')
	{
	// map -> data[map->p_i][map->p_j] = '0';
	// map -> data[map_i][map_j] = c;	
	destroy_win(map);
	exit(0);
	}
	if (map -> data[map_i][map_j] == 'C')
		map -> coins += 1;
	map -> data[map->p_i][map->p_j] = '0';
	map -> data[map_i][map_j] = c;
	// ft_putstr_fd("total fo movement = ");
	
	// if (map -> data[map_i][map_j] == 'E')
	// {
	// 	destroy_win(map);
	// 	exit(0);
	// }	
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

int	destroy_win(t_map *map)
{
		destroy_image(map);
		mlx_clear_window(map -> mlx, map -> win);
		mlx_destroy_window(map -> mlx, map -> win);
		map -> win = NULL;
		mlx_destroy_display(map -> mlx); 
		free(map -> win);
		free(map->mlx);	
		ft_free(map -> data);
		
		exit(0);
		return (0);
}


int	key_hook(int key_code,t_map *map)
{

	int map_i;
	int map_j;

	map_i = map -> p_i;
	map_j = map -> p_j;
	if (key_code == 65307)
	{
		destroy_win(map);
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
	// printf(" address of my map at each movement %p\n", map -> data);
	return (0);
}



int	main(int ac, char **av)
{
	t_map map;
	t_asset check;
	char **tab;

	if (ac == 1)
		return (0);
	if (parsing(av, &check))
	{
		tab = create_tab(av);
		if (!tab)
			return (0);
		if(!check_size(tab, &check))
  	 {
      	 printf("Error size\n");
	 	  ft_free(tab);
       	return(0);
  	 }
	if (!init_window(&map, tab))
		return (0);
	init_map(&map, tab);
	}
	else
		return (0);
   	create_map(&map);
	mlx_key_hook(map.win,&key_hook,&map);
	mlx_hook(map.win, ClientMessage, LeaveWindowMask,
		&destroy_win, &map);
	mlx_loop(map.mlx);
	return (0);
}