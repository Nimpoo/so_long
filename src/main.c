/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihemayoub <sihemayoub@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:30:18 by mayoub            #+#    #+#             */
/*   Updated: 2023/07/19 21:26:10 by sihemayoub       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_sad(int i)
{
	exit(!printf("Error\nwrong config bro >:(\n") + i - i);
}

void	ini_so_long(int fd, t_game *all)
{
	map_read(fd, all);
	ini_mlx(all);
	ft_ini_sprites(all);
	ft_graphic(all);
}

void	ft_check_after_point(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 4] != '.')
		ft_sad(i);
	i--;
	if (str[i] != 'r')
		ft_sad(i);
	i--;
	if (str[i] != 'e')
		ft_sad(i);
	i--;
	if (str[i] != 'b')
		ft_sad(i);
	i--;
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
	ft_check_after_point(argv[1]);
	fd = open(argv[1], O_RDONLY);
	ini_so_long(fd, &all);
	all.steps = 0;
	printf("ta trainée de larmes bien salées : %d\n", all.steps);
	mlx_hook(all.win, 2, 0, deplacement, (void *)&all);
	mlx_hook(all.win, 17, 0, kill_window, (void *)&all);
	mlx_loop_hook(all.mlx, ft_refresh, &all);
	mlx_loop(all.mlx);
	close(fd);
}
