/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihemayoub <sihemayoub@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 02:06:34 by mayoub            #+#    #+#             */
/*   Updated: 2023/07/19 17:29:12 by sihemayoub       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	kill_player(t_game *all)
{
	printf("CONGLATURATION\n");
	all->map.map[all->pos.p_player.x][all->pos.p_player.y] = '0';
	ft_graphic(all);
	exit(0);
}

void	put_steps(t_game *all)
{
	char	*str;

	str = ft_itoa(all->steps);
	mlx_string_put(all->mlx, all->win, 64, 64, 0x9400D3, str);
	free(str);
}

int	ft_check_wall(t_game *all, int col, int line)
{
	if (all->map.map[line][col] == '1')
		return (0);
	if (all->map.map[line][col] == 'E' && all->objects.coin == 0)
		all->end_game = 1;
	if (all->map.map[line][col] == 'E')
		return (0);
	if (all->map.map[line][col] == 'V')
	{
		all->end_game = 2;
		return (0);
	}
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
	if (all->end_game == 2)
		killed_by_vilain(all);
	if (valid == 1)
	{
		if (all->map.map[line][col] == 'C')
			all->objects.coin--;
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
		line--;
	if (key == DOWN)
		line++;
	if (key == LEFT)
		col--;
	if (key == RIGHT)
		col++;
	if (key == ESC)
		kill_window(all);
	check_key(all, key);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
	{
		ft_update(col, line, all);
		printf("ta trainée de larmes bien salées : %d\n", all->steps);
	}
	return (1);
}
