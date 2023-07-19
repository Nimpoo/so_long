/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vilain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihemayoub <sihemayoub@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:37:37 by mayoub            #+#    #+#             */
/*   Updated: 2023/07/19 17:16:49 by sihemayoub       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_wall_vilains(t_game *all, int col, int line)
{
	if (all->map.map[line][col] == 1)
		return (0);
	return (1);
}

void	deplacement_vilain(int col, int line, t_game *all)
{
	int	x;
	int	y;
	int	valid;

	x = all->pos.p_vilain.x;
	y = all->pos.p_vilain.y;
	valid = ft_check_wall_vilains(all, col, line);
	if (valid == 1)
	{
		all->map.map[x][y] = '0';
		all->map.map[line][col] = 'V';
		all->pos.p_player.x = line;
		all->pos.p_player.y = col;
		all->steps++;
	}
}

void	vilains_pos(t_game *all)
{
	int	col;
	int	line;

	col = all->pos.p_vilain.y;
	line = all->pos.p_vilain.x;
	deplacement_vilain(col, line, all);
}

void	killed_by_vilain(t_game *all)
{
	printf("GAME OVER\n");
	all->map.map[all->pos.p_player.x][all->pos.p_player.y] = '0';
	ft_graphic(all);
	exit(0);
}
