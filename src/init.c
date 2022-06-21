/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:24:05 by lcorpora          #+#    #+#             */
/*   Updated: 2022/06/10 18:24:07 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_img(t_map *map)
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
	if (!map -> img.wall || !map -> img.coin || !map -> img.exit
		|| !map -> img.player || !map -> img.tiles)
		return (0);
	return (1);
}

int	init_map(t_map *map, t_asset *check)
{
	map -> img.height = SIZE;
	map -> img.width = SIZE;
	map -> movement = 0;
	map -> p_i = 0;
	map -> p_j = 0;
	map -> coins = 0;
	map -> total_coins = count_coins(map -> data);
	if (!init_img(map))
	{
		check -> img = 0;
		error_map(check);
		return (0);
	}
	return (1);
}

int	init_window(t_map *map, char **tab)
{
	map -> mlx = mlx_init();
	if (map -> mlx == NULL)
		return (0);
	map -> win = mlx_new_window(map -> mlx, ft_strlen(tab[1]) * SIZE + 1,
			tab_len(tab) * SIZE + 1, "Hey Molly!");
	if (map -> win == NULL)
		return (0);
	return (1);
}
