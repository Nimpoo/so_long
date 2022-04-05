/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:17:45 by mayoub            #+#    #+#             */
/*   Updated: 2022/04/05 02:50:24 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ground(t_game *all, void *mlx, void *win)
{
	void	*img;

	img = NULL;
	ini_variable(all);
	while (all->map.map[all->var.i] != NULL)
	{
		if (all->map.map[all->var.i][all->var.j] == '\0')
			backslash_n(all);
		img = all->img.ground;
		mlx_put_image_to_window(mlx, win, img, all->var.d_x, all->var.d_y);
		all->var.d_x += 64;
		all->var.j++;
	}
}

void	ft_graphic(t_game *all, void *mlx, void *win)
{
	void	*img;

	img = NULL;
	ini_variable(all);
	while (all->map.map[all->var.i] != NULL)
	{
		if (all->map.map[all->var.i][all->var.j] == '\0')
			backslash_n(all);
		else if (all->map.map[all->var.i][all->var.j] == '1')
			colle_image_wall(all, mlx, win);
		else if (all->map.map[all->var.i][all->var.j] == 'C')
			colle_image_coin(all, mlx, win);
		else if (all->map.map[all->var.i][all->var.j] == 'E')
			colle_image_exit(all, mlx, win);
		else if (all->map.map[all->var.i][all->var.j] == 'P')
			colle_image_player(all, mlx, win);
		else if (all->map.map[all->var.i][all->var.j] == 'V')
			colle_image_vilain(all, mlx, win);
		else
		{	
			all->var.d_x += 64;
			all->var.j++;
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
	win = mlx_new_window(mlx, all->map.lengh * 64, all->map.height * 64,
			"so_long");
	ft_ini_sprites(all, mlx);
	ft_ground(all, mlx, win);
	ft_graphic(all, mlx, win);
	mlx_key_hook(win, tester, all),
	mlx_loop(mlx);
}
