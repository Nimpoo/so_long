/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihemayoub <sihemayoub@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:29:43 by mayoub            #+#    #+#             */
/*   Updated: 2023/07/19 17:16:49 by sihemayoub       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	colle_image_wall(t_game *all)
{
	mlx_put_image_to_window(all->mlx, all->win, all->img.wall, all->var.d_x,
		all->var.d_y);
	all->var.d_x += 64;
	all->var.j++;
}

void	colle_image_coin(t_game *all)
{
	mlx_put_image_to_window(all->mlx, all->win, all->img.coin, all->var.d_x,
		all->var.d_y);
	all->var.d_x += 64;
	all->var.j++;
}

void	colle_image_player(t_game *all)
{
	if (all->side.side_p == DOWN)
		mlx_put_image_to_window(all->mlx, all->win, all->img.player_front,
			all->var.d_x, all->var.d_y);
	else if (all->side.side_p == UP)
		mlx_put_image_to_window(all->mlx, all->win, all->img.player_back,
			all->var.d_x, all->var.d_y);
	else if (all->side.side_p == RIGHT)
		mlx_put_image_to_window(all->mlx, all->win, all->img.player_right,
			all->var.d_x, all->var.d_y);
	else if (all->side.side_p == LEFT)
		mlx_put_image_to_window(all->mlx, all->win, all->img.player_left,
			all->var.d_x, all->var.d_y);
	all->var.d_x += TILE;
	all->var.j++;
}

void	colle_image_exit(t_game *all)
{	
	mlx_put_image_to_window(all->mlx, all->win, all->img.exit, all->var.d_x,
		all->var.d_y);
	all->var.d_x += 64;
	all->var.j++;
}

void	colle_image_vilain(t_game *all)
{
	all->pos.p_vilain.x = all->var.v_i;
	all->pos.p_vilain.y = all->var.v_j;
	if (all->side.side_v == DOWN)
		mlx_put_image_to_window(all->mlx, all->win, all->img.vilain_front,
			all->var.d_x, all->var.d_y);
	else if (all->side.side_v == UP)
		mlx_put_image_to_window(all->mlx, all->win, all->img.vilain_back,
			all->var.d_x, all->var.d_y);
	else if (all->side.side_v == RIGHT)
		mlx_put_image_to_window(all->mlx, all->win, all->img.vilain_right,
			all->var.d_x, all->var.d_y);
	else if (all->side.side_v == LEFT)
		mlx_put_image_to_window(all->mlx, all->win, all->img.vilain_left,
			all->var.d_x, all->var.d_y);
	all->var.d_x += 64;
	all->var.j++;
}
