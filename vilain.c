/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vilain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:37:37 by mayoub            #+#    #+#             */
/*   Updated: 2022/04/13 18:31:04 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	killed_by_vilain(t_game *all)
{
	printf("GAME OVER\n");
	all->map.map[all->pos.p_player.x][all->pos.p_player.y] = '0';
	ft_graphic(all);
	exit(0);
}

void	ft_update_vilain(int col, int line, t_game *all)
{
	int	x;
	int	y;
	int	valid;

	x = all->pos.p_vilain.x;
	y = all->pos.p_vilain.y;
	valid = ft_check_wall(all, col, line);
	if (valid == 1)
	{
		all->map.map[x][y] = '0';
		all->map.map[line][col] = 'V';
		all->pos.p_vilain.x = line;
		all->pos.p_vilain.y = col;
	}
}

int	deplacement_vilain(t_game *all)
{
	int	col;
	int	line;

	col = all->pos.p_vilain.y;
	line = all->pos.p_vilain.x;
	if (col % 2)
	{
		all->pos.p_vilain.y--;
		// if (ft_check_wall(all, col, line) != 0)
		// 	line--;
		// if (ft_check_wall(all, col, line) == 0)
		// 	line++;
		// if (ft_check_wall(all, col, line) != 0)
		// 	line++;
		// if (ft_check_wall(all, col, line) == 0)
		// 	line--;
	}
	else
	{
		all->pos.p_vilain.x--;
		// if (ft_check_wall(all, col, line) != 0)
		// 	col--;
		// if (ft_check_wall(all, col, line) == 0)
		// 	col++;
		// if (ft_check_wall(all, col, line) != 0)
		// 	col++;
		// if (ft_check_wall(all, col, line) == 0)
		// 	col--;
	}
	ft_update_vilain(col, line, all);
	return (1);
}
