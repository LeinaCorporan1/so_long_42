/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:24:40 by lcorpora          #+#    #+#             */
/*   Updated: 2022/06/10 18:24:42 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_map *map, int map_i, int map_j)
{
	char	c;

	map -> movement += 1;
	move_msg(map -> movement);
	c = map -> data[map -> p_i][map -> p_j];
	if (map -> data[map_i][map_j] == 'E')
	{
		destroy_win(map);
		exit(0);
	}
	if (map -> data[map_i][map_j] == 'C')
		map -> coins += 1;
	map -> data[map -> p_i][map -> p_j] = '0';
	map -> data[map_i][map_j] = c;
}

int	check_move(t_map *map, int map_i, int map_j)
{
	if (map_i == map -> p_i && map_j == map -> p_j)
		return (0);
	if (map -> data [map_i][map_j] == '1')
		return (0);
	if (map -> data [map_i][map_j] == 'E'
	&& map -> coins != map -> total_coins)
		return (0);
	return (1);
}

int	key_hook(int key_code, t_map *map)
{
	int	map_i;
	int	map_j;

	map_i = map -> p_i;
	map_j = map -> p_j;
	if (key_code == 65307)
		destroy_win(map);
	if (key_code == 97 || key_code == 65361)
		map_j--;
	if (key_code == 100 || key_code == 65363)
		map_j++;
	if (key_code == 119 || key_code == 65362)
		map_i--;
	if (key_code == 115 || key_code == 65364)
		map_i++;
	if (check_move(map, map_i, map_j))
		move(map, map_i, map_j);
	create_map(map);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_asset	check;

	map.data = NULL;
	if (ac == 1)
		return (0);
	if (!check_error(av, &check, &map))
		return (0);
	if (!init_window(&map, map.data))
		return (0);
	if (!init_map(&map, &check))
		destroy_win(&map);
	create_map(&map);
	mlx_key_hook(map.win, &key_hook, &map);
	mlx_hook(map.win, ClientMessage, LeaveWindowMask,
		&destroy_win, &map);
	mlx_loop(map.mlx);
	return (0);
}
