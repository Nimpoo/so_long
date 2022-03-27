/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:30:18 by mayoub            #+#    #+#             */
/*   Updated: 2022/03/27 11:15:26 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_sad(int i)
{
	(void) i;
	printf("Error\nwrong config bro >:(\n");
	exit (0);
}

char	**ini_so_long(int fd, t_game *all)
{
	char	**str;
	int		i;
	int		k;

	k = 0;
	i = 0;
	str = NULL;
	map_read(fd, all);
	return (str);
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
	ini_so_long(fd, &all);
	printf("coin = %d, player = %d, exit = %d, height = %d, lengh = %d\n", all.objects.coin, all.objects.player, all.objects.end, all.map.height, all.map.lengh);
	window(&all);
	close(fd);
}
