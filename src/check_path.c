/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:37:25 by lcorpora          #+#    #+#             */
/*   Updated: 2022/09/09 17:37:29 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	init_path(t_path *path)
{
	int	i;
	int	y;

	i = -1;
	while (path->data[++i])
	{
		y = 0;
		while (path->data[i][y])
		{
			if (path->data[i][y] == 'E')
			{
				path->exit_row = i;
				path->exit_column = y;
			}
			if (path->data[i][y] == 'P')
			{
				path->pos_row = i;
				path->pos_column = y;
			}
			y++;
		}
	}
	path->cnt_coins = count_coins(path->data);
}

int	valid(int row, int column, t_path *path)
{
	if (path->data[row][column] == '1')
		return (0);
	if (path->data[row][column] == 'V')
		return (0);
	if (path->data[row][column] == 'N')
		return (0);
	if (path->data[row][column] == 'E' && path->cnt_coins != 0)
		return (0);
	return (1);
}

int	push_direction(t_path *path)
{
	path->mov_row = 0;
	path->mov_column = 0;
	if (valid(path->pos_row, path->pos_column - 1, path))
		path->mov_column = -1;
	else if (valid(path->pos_row, path->pos_column + 1, path))
		path->mov_column = 1;
	else if (valid(path->pos_row + 1, path->pos_column, path))
		path->mov_row = 1;
	else if (valid(path->pos_row - 1, path->pos_column, path))
		path->mov_row = -1;
	if (path->mov_row == 0 && path->mov_column == 0)
		return (0);
	else
		return (1);
}

int	check_path(char **av, t_path *path, t_asset *check)
{
	t_track	*track;

	track = NULL;
	path->data = create_tab(av, path->data);
	init_path(path);
	track = add_empty(&track, path->pos_row, path->pos_column);
	while (path->data[path->pos_row][path->pos_column] != 'E' && !check->path)
	{
		if (push_direction(path))
			found_track(track, path);
		else
			err_track(track, path, check);
	}
	free_lst(&track);
	ft_free(path->data);
	if (check->path == 0)
		return (1);
	else
		return (0);
}
