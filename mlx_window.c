/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:17:45 by mayoub            #+#    #+#             */
/*   Updated: 2022/03/30 18:56:02 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ini_sprites(t_game *all, void *mlx)
{
	all->img.ground = mlx_xpm_file_to_image
		(mlx, "./sprites/ground.xpm", &all->map.lengh, &all->map.height);
	all->img.wall = mlx_xpm_file_to_image
		(mlx, "./sprites/wall.xpm", &all->map.lengh, &all->map.height);
	all->img.exit = mlx_xpm_file_to_image(
			mlx, "./sprites/exit.xpm", &all->map.lengh, &all->map.height);
	all->img.coin = mlx_xpm_file_to_image(
			mlx, "./sprites/coin.xpm", &all->map.lengh, &all->map.height);
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

void	ft_ground(t_game *all, void *mlx, void *win)
{
	int		i;
	int		j;
	int		delay_x;
	int		delay_y;
	void	*img;

	i = 0;
	j = 0;
	delay_x = 0;
	delay_y = 0;
	while (all->map.map[i] != NULL)
	{
		if (all->map.map[i][j] == '\0')
		{
			delay_y += 64;
			i++;
			delay_x = 0;
			j = 0;
		}
		img = all->img.ground;
		mlx_put_image_to_window(mlx, win, img, delay_x, delay_y);
		delay_x += 64;
		j++;
	}
}

void	ft_wall(t_game *all, void *mlx, void *win)
{
	int		i;
	int		j;
	int		delay_x;
	int		delay_y;
	void	*img;

	i = 0;
	j = 0;
	delay_x = 0;
	delay_y = 0;
	while (all->map.map[i] != NULL)
	{
		if (all->map.map[i][j] == '\0')
		{
			delay_y += 64;
			i++;
			delay_x = 0;
			j = 0;
		}
		else if (all->map.map[i][j] == '1')
		{
			img = all->img.wall;
			mlx_put_image_to_window(mlx, win, img, delay_x, delay_y);
			delay_x += 64;
			j++;
		}
		else
		{	
			delay_x += 64;
			j++;
		}
	}
}

void	window(t_game *all)
{
	void	*mlx;
	void	*win;
	int		i;

	i = 0;
	printf("%d, %d\n", all->map.height, all->map.lengh);
	mlx = mlx_init();
	win = mlx_new_window(mlx, all->map.lengh * 64, all->map.height * 64, "so_long");
	ft_ini_sprites(all, mlx);
	ft_ground(all, mlx, win);
	ft_wall(all, mlx, win);
	mlx_loop(mlx);
}
