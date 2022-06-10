/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:23:51 by lcorpora          #+#    #+#             */
/*   Updated: 2022/06/10 18:23:53 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image(t_map *map)
{
	if (map -> img.wall)
		mlx_destroy_image(map -> mlx, map -> img.wall);
	if (map -> img.player)
		mlx_destroy_image(map -> mlx, map -> img.player);
	if (map -> img.coin)
		mlx_destroy_image(map -> mlx, map -> img.coin);
	if (map -> img.exit)
		mlx_destroy_image(map -> mlx, map -> img.exit);
	if (map -> img.tiles)
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
