/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 02:06:34 by mayoub            #+#    #+#             */
/*   Updated: 2022/04/09 06:53:19 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	kill_player(t_game *all)
{
	all->map.map[all->pos.p_player.y][all->pos.p_player.x] = '0';
	ft_graphic(all);
	printf("CONGLATULATION\n");
}

int	ft_check_wall(t_game *all, int col, int line)
{
	if (all->map.map[line][col] == '1')
		return (0);
	if (all->map.map[line][col] == 'E' && all->objects.coin == 0)
		all->end_game = 1;
	if (all->map.map[line][col] == 'E')
		return (0);
	/*if (all->map.map[line][col] == 'V')
		return (0);*/
	return (1);
}

void	ft_update(int col, int line, t_game *all)
{
	int	x;
	int	y;
	int	valid;

	x = all->pos.p_player.x;
	y = all->pos.p_player.y;
	valid = ft_check_wall(all, col, line);
	if (all->end_game == 1)
		kill_player(all);
	if (valid == 1)
	{
		if (all->map.map[line][col] == 'C')
		{
			all->objects.coin--;
			printf("%d\n", all->objects.coin);
		}
		all->map.map[x][y] = '0';
		all->map.map[line][col] = 'P';
		all->pos.p_player.x = line;
		all->pos.p_player.y = col;
		all->steps++;
	}
}

int	deplacement(int key, t_game *all)
{
	int	col;
	int	line;

	col = all->pos.p_player.y;
	line = all->pos.p_player.x;
	if (key == UP)
	{
		line--;
		all->side.side_p = UP;
	}
	if (key == DOWN)
	{
		line++;
		all->side.side_p = DOWN;
	}
	if (key == LEFT)
	{
		col--;
		all->side.side_p = LEFT;
	}
	if (key == RIGHT)
	{
		col++;
		all->side.side_p = RIGHT;
	}
	if (key == ESC)
		kill_window(all);
	ft_update(col, line, all);
	return (1);
}
