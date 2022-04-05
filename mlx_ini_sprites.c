/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ini_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:13:54 by mayoub            #+#    #+#             */
/*   Updated: 2022/04/05 03:27:21 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ini_sprites(t_game *all, void *mlx)
{
	all->img.ground = mlx_xpm_file_to_image
		(mlx, "./sprites/ground.xpm", &all->map.lengh, &all->map.height);
	all->img.wall = mlx_xpm_file_to_image
		(mlx, "./sprites/wall.xpm", &all->map.lengh, &all->map.height);
	all->img.exit = mlx_xpm_file_to_image
		(mlx, "./sprites/exit.xpm", &all->map.lengh, &all->map.height);
	all->img.coin = mlx_xpm_file_to_image
		(mlx, "./sprites/coin.xpm", &all->map.lengh, &all->map.height);
	all->img.player_front = mlx_xpm_file_to_image
		(mlx, "./sprites/player_front.xpm", &all->map.lengh, &all->map.height);
	all->img.player_back = mlx_xpm_file_to_image
		(mlx, "./sprites/player_back.xpm", &all->map.lengh, &all->map.height);
	all->img.player_left = mlx_xpm_file_to_image
		(mlx, "./sprites/player_left.xpm", &all->map.lengh, &all->map.height);
	all->img.player_right = mlx_xpm_file_to_image
		(mlx, "./sprites/player_right.xpm", &all->map.lengh, &all->map.height);
	all->img.vilain_front = mlx_xpm_file_to_image
		(mlx, "./sprites/vilain_front.xpm", &all->map.lengh, &all->map.height);
	all->img.vilain_back = mlx_xpm_file_to_image
		(mlx, "./sprites/vilain_back.xpm", &all->map.lengh, &all->map.height);
	all->img.vilain_left = mlx_xpm_file_to_image
		(mlx, "./sprites/vilain_left.xpm", &all->map.lengh, &all->map.height);
	all->img.vilain_right = mlx_xpm_file_to_image
		(mlx, "./sprites/vilain_right.xpm", &all->map.lengh, &all->map.height);
}

void	ini_variable(t_game *all)
{
	all->var.i = 0;
	all->var.j = 0;
	all->var.d_x = 0;
	all->var.d_y = 0;
}

void	backslash_n(t_game *all)
{
	all->var.d_y += 64;
	all->var.i++;
	all->var.d_x = 0;
	all->var.j = 0;
}
