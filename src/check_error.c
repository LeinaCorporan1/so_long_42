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

// void	ft_printdbl(char **tmp, int r, int c)
// {
// 	int	i;
// 	int	y;

// 	i = 0;
// 	while(tmp[i])
// 	{
// 		y = 0;
// 		while(tmp[i][y])
// 		{
// 			if (i == r && y == c)
// 				printf("\x1B[31m");
// 			printf("%c  ",tmp[i][y] );
// 			printf("\033[0;37m");
// 			y++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

// void    print_lst(t_track *lst)
// {
// 	if (lst == NULL)
// 		return ;
// 	while (lst != NULL)
// 	{
// 		printf("row = %d column  = %d\n", lst -> row, lst -> column);
// 		lst = lst -> next;
// 	}
// 	printf("\n");
// }

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
		return NULL;
	add = (t_track *)malloc(sizeof(t_track));
	add->prev = NULL;
	add->row = data_row;
	add->column = data_column;
	add->next = NULL;
	*track = add;
	return (*track);

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

void	change_pos(t_track *track, t_path *path)
{
	t_track *tmp;

	tmp = track;
	while (tmp->next != NULL)
		tmp = tmp->next;
	path->pos_row = tmp->row;
	path->pos_column = tmp->column;
}

int	check_path(char **av, t_path *path, t_asset *check)
{
	t_track *track;

	track = NULL;
	path->data = create_tab(av, path->data);
	init_path(path);
	track = add_empty(&track, path->pos_row, path->pos_column);
	while (path->data[path->pos_row][path->pos_column] != 'E' && !check->path)
	{
		if (push_direction(path))
		{
			add_track(track, path->pos_row, path->pos_column);
			path->data[path->pos_row][path->pos_column] = 'V';
			path->pos_row = path->pos_row + path->mov_row;
			path->pos_column = path->pos_column + path->mov_column;
			if (path->data[path->pos_row][path->pos_column] == 'C')
					path->cnt_coins--;
			// printf("push direction worked\n");//
			// ft_printdbl(path->data, path->pos_row, path->pos_column);//

			}
		else
		{
			path->data[path->pos_row][path->pos_column] = '1';
			change_pos(track, path);
			if (track->next == NULL)
				check->path = 1;
			else
				supp_track(track);
			// printf("push_direction do not fund any direction possible and coins = %d\n", path->cnt_coins);//
			// ft_printdbl(path->data, path->pos_row, path->pos_column);//
		}
	}
	free_lst(&track);
	ft_free(path->data);
	if (check->path == 0)
		return (1);
	else
		return (0);
}

int	extension_check(char **av, char *extention)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(av[1]);
	printf ("my i = %d and ext = %ld\n", i, ft_strlen(extention));
	i = i - ft_strlen(extention);
	if (i == 0 || av[1][i - 1] == '/')
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
	check -> path = 0;
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
	if (!check_map(map -> data, check) || (!check_path(av, path, check)))
	{
		error_map(check);
		ft_free(map -> data);
		return (0);
	}
	// if (!check_path(av, path))
	// 	printf("my map is impossible\n");
	// check_path(av, path);
	return (1);
}
