/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:24:13 by lcorpora          #+#    #+#             */
/*   Updated: 2022/06/10 18:24:15 by lcorpora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_map(t_asset	*check)
{
	ft_putstr_fd("Error\n", 1);
	if (check -> p == 0)
		ft_putstr_fd ("There is no player in the map !\n", 1);
	if (check -> c == 0)
		ft_putstr_fd ("There is no coin in the map !\n", 1);
	if (check -> e == 0)
		ft_putstr_fd ("There is no exit in the map !\n", 1);
	if (check -> line == 0)
		ft_putstr_fd ("The map is missing walls !\n", 1);
	if (check -> rect == 0)
		ft_putstr_fd ("The map is not a rectangular !\n", 1);
	if (check -> img == 0)
		ft_putstr_fd (" The map can not be created, the img is invalid ! \n", 1);
}

void	error_extension(void)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd ("The map is not valid !\n", 1);
}

void	move_msg(int move)
{
	ft_putstr_fd("move counter = ", 1);
	ft_putnbr_fd(move, 1);
	ft_putstr_fd("\n", 1);
}
