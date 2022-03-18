/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.C                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:30:18 by mayoub            #+#    #+#             */
/*   Updated: 2022/03/18 08:51:57 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_solen(char *str, char a)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != a)
			return (-1);
		i++;
	}
	return (i);
}

char	**ini_so_long(int fd)
{
	char	**str;
	int		i;
	int		k;

	k = 0;
	i = 0;
	str = NULL;
	map_read(fd);
	return (str);
}

int	main(int argv, char **argc)
{
	int	fd;
	int	i;

	(void) argv;
	i = 0;
	while (argc[i])
		i++;
	if (i > 2)
	{
		printf("Error\nwrong config bro >:(\n");
		return (0);
	}
	fd = open(argc[1], O_RDONLY);
	ini_so_long(fd);
	close(fd);
}
