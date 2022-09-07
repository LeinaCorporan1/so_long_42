/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:23:36 by lcorpora          #+#    #+#             */
/*   Updated: 2022/06/10 18:23:39 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

void    print_lst(t_track *lst)
{
    if (lst == NULL)
        return ;
    while (lst -> next != NULL)
    {
        printf("row = %d\n", lst -> row);
        printf("column  = %d\n", lst -> column);
        lst = lst -> next;
    }
        printf("row = %d\n", lst -> row);
        printf("column  = %d\n", lst -> column);
	printf("\n");
}

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

void	add_empty(t_track *track, int data_row, int data_column)
{
	t_track	*add;

	if (track)
		return ;
	add = (t_track *)malloc(sizeof(t_track));
	add->prev = NULL;
	add->row = data_row;
	add->column = data_column;
	add->next = NULL;
	track = add;
}

void add_track(t_track *track, int data_row, int data_column)
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
	track = temp;
}

int	 search_coin (t_path *path)
{
	int	i;
	int	y;

	i = 0;
	while (path->data[i])
	{
		y = 0;
		while (path->data[i][y])
		{
			if (path->data[i][y] == 'C')
			{
				path->coin_column = y;
				path->coin_row = i;
				return (1);
			}
			y++;
		}
		i++;
	}
	return (0);
}

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
	path->count_coins = count_coins(path->data);
	// path->mov_row = start_i;
	// path->mov_column = start_j;
}

int	valid(int row, int column, t_path *path)
{
	if (path->data[row][column] == '1')
		return (0);
	if (path->data[row][column] == 'N')
		return (0);
	if (path->data[row][column] == 'E' && path->count_coins != 0)
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

void	check_path(char **av, t_path *path)
{
	t_track track;
	int		impossible;

	impossible = 0;
	
	path->data = create_tab(av, path->data);
	init_path(path);
	add_empty(&track, path->pos_row, path->pos_column);
	printf("my sart i = %d startj = %d\n", path->pos_row, path->pos_column);
	print_lst(&track);
	while (path->data[path->pos_row][path->pos_column] != 'E' || !impossible)
	{
		if (push_direction(path))
			{
				add_track(&track, path->pos_row, path->pos_column);
				path->data[path->pos_row][path->pos_column] = '1';
				path->pos_row = path->pos_row + path->mov_row;
				path->pos_column = path->pos_column + path->mov_column;
				print_lst(&track);
			}
		else
			break;
	}
	printf("my data = %c\n", path->data[0][4]);
}



















int	extension_check(char **av, char *extention)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(av[1]);
	i = i - ft_strlen(extention);
	if (i == 0)
		return (0);
	while (av[1][i])
	{
		if (av[1][i] != extention[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

char	**check_asset(char **tab, t_asset *check, int i, int k)
{
	i = 0;
	k = 0;
	while (tab[i])
	{
		if (tab[i][0] != '1' || tab[i][ft_strlen(tab[0]) - 1] != '1')
			check -> line = 0;
		k = 0;
		while (tab[i][k])
		{
			if (tab[i][k] == 'P' && check -> p == 1)
				tab[i][k] = '0';
			if (tab[i][k] == 'E')
				check -> e = 1;
			if (tab[i][k] == 'C')
				check -> c = 1;
			if (tab[i][k] == 'P')
				check -> p = 1;
			k++;
		}
		i++;
	}
	return (tab);
}

int	check_map(char **tab, t_asset *check)
{
	int		i;
	int		k;
	size_t	j;

	i = 1;
	j = ft_strlen((const char *)tab[0]);
	while (tab[i])
	{
		if (ft_strlen((const char *)tab[i]) != j)
			check -> rect = 0;
		i++;
	}
	i--;
	k = 0;
	while (tab[i][k] && tab[0][k])
	{
		if (tab[i][k] != '1' || tab[0][k] != '1')
			check -> rect = 0;
		k++;
	}
	tab = check_asset(tab, check, i, k);
	if (check -> e != 1 || check -> c != 1
		|| check -> p != 1 || check -> line != 1 || check -> rect != 1)
		return (0);
	return (1);
}

int	check_error(char **av, t_asset *check, t_map *map, t_path *path)
{
	check -> e = 0;
	check -> c = 0;
	check -> p = 0;
	check -> line = 1;
	check -> rect = 1;
	check -> img = 1;
	if (!extension_check(av, EXTENSION))
	{
		error_extension();
		return (0);
	}
	map -> data = create_tab(av, map -> data);
	if (map -> data == NULL)
	{
		error_extension();
		return (0);
	}
	if (!check_map(map -> data, check))
	{
		error_map(check);
		ft_free(map -> data);
		return (0);
	}
	check_path(av, path);
	return (1);
}