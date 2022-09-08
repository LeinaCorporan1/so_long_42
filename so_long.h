/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:25:26 by lcorpora          #+#    #+#             */
/*   Updated: 2022/06/10 18:25:28 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx_linux/mlx.h"
# include "libft/libft.h"

# define PLAYER "img_xpm/player.xpm"
# define COIN "img_xpm/coin.xpm"
# define EXIT "img_xpm/exit.xpm"
# define TILES "img_xpm/tile.xpm"
# define WALL "img_xpm/wall.xpm"
# define SIZE 64
# define EXTENSION ".ber"

typedef struct s_asset
{
	int	e;
	int	c;
	int	p;
	int	line;
	int	rect;
	int	img;
	int	path;
}	t_asset;

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*tiles;
	void	*coin;
	void	*exit;
	int		height;
	int		width;
}	t_img;

typedef struct s_map
{
	void	*mlx;
	void	*win;
	char	**data;
	int		p_i;
	int		p_j;
	int		movement;
	int		coins;
	int		total_coins;
	t_img	img;

}	t_map;

typedef struct s_track
{
	struct s_track	*prev;
	int		row;
	int		column;
	struct s_track *next;
} t_track;

typedef struct s_path
{
	int	exit_column;
	int	exit_row;
	int	pos_column;
	int	pos_row;
	int	coin_column;
	int	coin_row;
	int cnt_coins;
	int	mov_column;
	int	mov_row;
	char	**data;
}	t_path;

/*init.c*/

int		init_img(t_map *map);
int		init_map(t_map *map, t_asset *check);
int		init_window(t_map *map, char **tab);

/*parsing.c*/

char	*insert_tab(char *tab, char *buf, int ret, int fd);
char	**create_tab(char **av, char **final);
void	import_img(t_map *map, int i, int j);
int		create_map(t_map *map);

/*check_error.c*/

int		extention_check(char **av, char *extention);
char	**check_asset(char **tab, t_asset *check, int i, int k);
int		check_map(char **tab, t_asset *check);
int		check_error(char **av, t_asset *check, t_map *map, t_path *path);

/*destroy.c*/

void	destroy_image(t_map *map);
int		destroy_win(t_map *map);

/*so_long.c*/

void	move(t_map *map, int map_i, int map_j);
int		check_move(t_map *map, int map_i, int map_j);
int		key_hook(int key_code, t_map *map);

/*utils*/

int		count_coins(char **tab);
int		tab_len(char **tab);
void	ft_free(char **data);
char	*ft_strjoin_sl(char *s1, char const *s2);

/*msg.c*/

void	error_map(t_asset	*check);
void	error_extension(void);
void	move_msg(int move);

#endif
