/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:30:18 by mayoub            #+#    #+#             */
/*   Updated: 2022/04/13 18:08:56 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_sad(int i)
{
	(void) i;
	printf("Error\nwrong config bro >:(\n");
	exit (0);
}

int	ini_so_long(int fd, t_game *all)
{
	map_read(fd, all);
	printf("%d, %d\n", all->map.height, all->map.lengh);
	ini_mlx(all);
	ft_ini_sprites(all);
	ft_graphic(all);
	return (1);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_game		all;

	if (argc != 2)
	{
		printf("Error\nwrong config bro >:(\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (ini_so_long(fd, &all) < 0)
		return (0);
	printf("coin = %d, player = %d, exit = %d, height = %d, lengh = %d\n", all.objects.coin, all.objects.player, all.objects.end, all.map.height, all.map.lengh);
	all.steps = 0;
	printf("ta trainée de larmes bien salées : %d\n", all.steps);
	mlx_hook(all.win, 2, 0, deplacement, (void *)&all);
	mlx_hook(all.win, 17, 0, kill_window, (void *)&all);
	mlx_loop_hook(all.mlx, ft_refresh, &all);
	mlx_loop(all.mlx);
	close(fd);
}
