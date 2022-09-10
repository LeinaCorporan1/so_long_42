/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:36:59 by lcorpora          #+#    #+#             */
/*   Updated: 2022/09/09 17:37:06 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	supp_track(t_track *track)
{
	t_track	*remove;
	t_track	*new;

	remove = track;
	new = track;
	if (track == NULL)
		return ;
	while (remove->next != NULL)
		remove = remove->next;
	new = remove->prev;
	new->next = NULL;
	free(remove);
	track = new;
}

t_track	*add_empty(t_track **track, int data_row, int data_column)
{
	t_track	*add;

	if (!track)
		return (NULL);
	add = (t_track *)malloc(sizeof(t_track));
	add->prev = NULL;
	add->row = data_row;
	add->column = data_column;
	add->next = NULL;
	*track = add;
	return (*track);
}

void	add_track(t_track *track, int data_row, int data_column)
{
	t_track	*add;
	t_track	*temp;

	add = (t_track *)malloc(sizeof(t_track));
	add->prev = NULL;
	add->row = data_row;
	add->column = data_column;
	add->next = NULL;
	temp = track;
	while (temp -> next != NULL)
		temp = temp -> next;
	temp -> next = add;
	add -> prev = temp;
}

void	free_lst(t_track **track)
{
	t_track	*del;
	t_track	*tmp;

	del = *track;
	while (del != NULL)
	{
		tmp = del -> next;
		free(del);
		del = tmp;
	}
}
