/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:17:45 by mayoub            #+#    #+#             */
/*   Updated: 2022/03/27 17:30:18 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window(t_game *all)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;

	x = all->map.lengh;
	y = all->map.height;
	printf("%d, %d", all->map.height, all->map.lengh);
	mlx = mlx_init();
	win = mlx_new_window(mlx, x * 64, y * 64, "so_long");
	img = mlx_xpm_file_to_image(mlx, "sprites/ground.xpm", &x, &y);
	mlx_loop(mlx);
}
