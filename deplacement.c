/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 02:06:34 by mayoub            #+#    #+#             */
/*   Updated: 2022/04/08 06:31:21 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_update(int col, int line, t_game *all)
{
	int	x;
	int	y;

	x = all->pos.p_player.x;
	y = all->pos.p_player.y;
	/*ft_check_wall();
	if (all->end_game == 1)
		kill_game();*/
	if (all->map.map[line][col] == 'C')
		all->objects.coin--;
	all->map.map[x][y] = '0';
	all->map.map[line][col] = 'P';
	all->pos.p_player.x = line;
	all->pos.p_player.y = col;
	//all->steps++;
}

int	tester(int i, t_game *all)
{
	int	col;
	int	line;

	col = all->pos.p_player.y;
	line = all->pos.p_player.x;
	if (i == UP)
	{
		// printf("%d\n", i);
		// all->map.map[all->var.i][all->var.j] = '0';
		// all->map.map[all->var.i - 1][all->var.j] = 'P';
		// printf("%c\n", all->pos.p_player);
		// ft_graphic(all);
		line--;
	}
	if (i == DOWN)
		line++;
	if (i == LEFT)
		col--;
	if (i == RIGHT)
		col++;
	ft_update(col, line, all);
	return (0);
}
