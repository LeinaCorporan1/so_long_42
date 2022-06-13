/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:24:24 by lcorpora          #+#    #+#             */
/*   Updated: 2022/06/10 18:24:27 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*insert_tab(char *tab, char *buf, int ret, int fd)
{
	if (ret <= 0)
		free(buf);
	while (ret > 0)
	{
		if (tab == NULL)
			tab = ft_strdup(buf);
		else
		{
			if (buf[0] == '\n' && tab[ft_strlen(tab) - 1] == '\n')
			{
				free(buf);
				free(tab);
				return (NULL);
			}
			tab = ft_strjoin_sl(tab, buf);
		}
		ret = read(fd, buf, 1);
		if (ret >= 0)
			buf[ret] = '\0';
	}
	return (tab);
}

char	**create_tab(char **av, char **final)
{
	char	*tab;
	char	*buf;
	int		ret;
	int		fd;

	tab = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = (char *)malloc(sizeof(char ) * 2);
	if (!buf)
		return (NULL);
	ret = read(fd, buf, 1);
	if (ret >= 0)
		buf[ret] = '\0';
	tab = insert_tab(tab, buf, ret, fd);
	if (tab == NULL)
	{
		free(tab);
		return (NULL);
	}
	final = ft_split(tab, '\n');
	free(buf);
	free(tab);
	return (final);
}

void	import_img(t_map *map, int i, int j)
{
	if (map -> data[i][j] == '1')
		mlx_put_image_to_window(map -> mlx, map -> win,
			map -> img.wall, j * SIZE, i * SIZE);
	if (map -> data[i][j] == '0')
		mlx_put_image_to_window(map -> mlx, map -> win,
			map -> img.tiles, j * SIZE, i * SIZE);
	if (map -> data[i][j] == 'C')
		mlx_put_image_to_window(map -> mlx, map -> win,
			map -> img.coin, j * SIZE, i * SIZE);
	if (map -> data[i][j] == 'E')
		mlx_put_image_to_window(map -> mlx, map -> win,
			map -> img.exit, j * SIZE, i * SIZE);
	if (map -> data[i][j] == 'P')
	{
		map -> p_i = i;
		map -> p_j = j;
		mlx_put_image_to_window(map -> mlx, map -> win,
			map -> img.player, j * SIZE, i * SIZE);
	}
}

int	create_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map -> data[i])
	{
		j = 0;
		while (map -> data[i][j])
		{
			import_img(map, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
