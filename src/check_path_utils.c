/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:37:40 by lcorpora          #+#    #+#             */
/*   Updated: 2022/09/09 17:37:44 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	change_pos(t_track *track, t_path *path)
{
	t_track	*tmp;

	tmp = track;
	while (tmp->next != NULL)
		tmp = tmp->next;
	path->pos_row = tmp->row;
	path->pos_column = tmp->column;
}

void	found_track(t_track *track, t_path *path)
{
	add_track(track, path->pos_row, path->pos_column);
	path->data[path->pos_row][path->pos_column] = 'V';
	path->pos_row = path->pos_row + path->mov_row;
	path->pos_column = path->pos_column + path->mov_column;
	if (path->data[path->pos_row][path->pos_column] == 'C')
		path->cnt_coins--;
}

void	err_track(t_track *track, t_path *path, t_asset *check)
{
	path->data[path->pos_row][path->pos_column] = '1';
	change_pos(track, path);
	if (track->next == NULL)
		check->path = 1;
	else
		supp_track(track);
}
