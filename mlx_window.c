/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:17:45 by mayoub            #+#    #+#             */
/*   Updated: 2022/04/08 06:33:53 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ground(t_game *all)
{
	void	*img;

	img = NULL;
	ini_variable(all);
	while (all->map.map[all->var.i] != NULL)
	{
		if (all->map.map[all->var.i][all->var.j] == '\0')
			backslash_n(all);
		img = all->img.ground;
		mlx_put_image_to_window(all->mlx, all->win, img,
			all->var.d_x, all->var.d_y);
		all->var.d_x += 64;
		all->var.j++;
	}
}

void	ft_graphic(t_game *all)
{
	ini_variable(all);
	while (all->map.map[all->var.i] != NULL)
	{
		if (all->map.map[all->var.i][all->var.j] == '\0')
			backslash_n(all);
		else if (all->map.map[all->var.i][all->var.j] == '1')
			colle_image_wall(all);
		else if (all->map.map[all->var.i][all->var.j] == 'C')
			colle_image_coin(all);
		else if (all->map.map[all->var.i][all->var.j] == 'E')
			colle_image_exit(all);
		else if (all->map.map[all->var.i][all->var.j] == 'P')
		{
			all->pos.p_player.x = all->var.i;
			all->pos.p_player.y = all->var.j;
			colle_image_player(all);
		}
		else if (all->map.map[all->var.i][all->var.j] == 'V')
			colle_image_vilain(all);
		else
		{	
			all->var.d_x += 64;
			all->var.j++;
		}
	}
}

void	window(t_game *all)
{
	int		i;

	i = 0;
	printf("%d, %d\n", all->map.height, all->map.lengh);
	ft_ini_sprites(all);
	ft_ground(all);
	ft_graphic(all);
	mlx_loop(all->mlx);
}
