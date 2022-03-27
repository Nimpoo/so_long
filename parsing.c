/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:53:01 by mayoub            #+#    #+#             */
/*   Updated: 2022/03/27 11:37:53 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_remains(int i, int truth, int k, char *str)
{
	if ((str[i] == '\0' && ((i) % truth) != k) && k + 1 == truth)
		ft_sad(i);
	else
	{
		i -= truth + 1;
		while (str[++i])
		{
			if (str[i] != '1')
				ft_sad(i);
		}
	}
	printf("k = %d, truth = %d\n", k, truth);
	return (1);
}

char	ft_guardian(char *str)
{
	int			i;
	int			k;
	int			truth;

	i = -1;
	while (str[++i] != '\n')
	{
		if (str[i] != '1')
			ft_sad(i);
	}
	truth = i;
	k = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] != '1' || str[i - 1] != '1'
				|| ((i - k) % truth) != 0)
				ft_sad(i);
			k += 1;
		}
		i++;
	}
	ft_remains(i, truth, k, str);
	return (1);
}

char	ft_location(char *str, t_game *all)
{
	int	i;

	i = -1;
	all->objects.player = 0;
	all->objects.coin = 0;
	all->objects.end = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == 'P')
			all->objects.player++;
		if (str[i] == 'C')
			all->objects.coin++;
		if (str[i] == 'E')
			all->objects.end++;
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'P'
			&& str[i] != 'E' && str[i] != '\n')
			ft_sad(i);
	}
	if (all->objects.player != 1 || all->objects.end <= 0
		|| all->objects.coin <= 0)
		ft_sad(i);
	ft_lengh_height(str, all);
	return (1);
}

int	ft_lengh_height(char *str, t_game *all)
{
	int	i;

	i = -1;
	all->map.height = 0;
	all->map.lengh = 0;
	while (str[++i])
	{
		if (str[i] == '\n')
			all->map.height++;
	}
	all->map.height++;
	i = -1;
	while (str[++i] != '\n')
		all->map.lengh++;
	return (1);
}

char	**map_read(int fd, t_game *all)
{
	int			i;
	char		**map;
	char		*str;
	char		*tmp;

	i = 0;
	str = get_next_line(fd);
	if (!str || str[0] == '\n')
		ft_sad(i);
	while (str != NULL)
	{
		i++;
		tmp = ft_strjoin(tmp, str);
		str = get_next_line(fd);
	}
	ft_guardian(tmp);
	ft_location(tmp, all);
	map = ft_split(tmp, '\n');
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (map);
}
