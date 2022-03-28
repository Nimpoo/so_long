/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:17:45 by mayoub            #+#    #+#             */
/*   Updated: 2022/03/28 18:03:30 by mayoub           ###   ########.fr       */
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
	int		i;

	x = all->map.lengh;
	y = all->map.height;
	i = 0;
	printf("%d, %d\n", all->map.height, all->map.lengh);
	mlx = mlx_init();
	win = mlx_new_window(mlx, x * 64, y * 64, "so_long");
	while (i < 3)
	{
		img = mlx_xpm_file_to_image(mlx, "./sprites/ground.xpm", &x, &y);
		mlx_put_image_to_window(mlx, win, img, x, y);
		i++;
		y += 64;
		x += 64;
	}
	mlx_loop(mlx);
}
