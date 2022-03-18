/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:53:01 by mayoub            #+#    #+#             */
/*   Updated: 2022/03/18 19:41:47 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_sad(int i)
{
	(void) i;
	printf("Error\nwrong config bro >:(\n");
	exit (0);
}

int	ft_remains(int i, int truth, int k, char *str)
{
	if (truth == 3)
	{
		i -= truth + 1;
		while (str[++i])
		{
			if (str[i] != '1')
				ft_sad(i);
		}
		return (1);
	}
	if ((str[i] == '\0' && ((i) % truth) != k) && k + 1 == truth)
	{
		printf("truth = %d i = %d et k = %d PROUTE\n", truth, i, k);
		ft_sad(i);
	}
	else
	{
		i -= truth + 1;
		while (str[++i])
		{
			if (str[i] != '1')
				ft_sad(i);
		}
	}
	return (1);
}

int		ft_strlen_until(char *str, char c)
{
	int	i = 0;
	if (!str)
		return 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void	ft_guardian(char **str)
{
	int	i = 1;
	int	line_size = 0;
	int	j = 0;

	line_size = ft_strlen_until(str[0], '\n');
	if (str[0][j] < line_size)
	{
		printf("WRONG SIZE LINE 1\n");
		exit(1);
	}
	while (str[0][j])
	{
		if (str[0][j] != '1')
		{
			printf("NOT ONLY 1 ON FIRST LINE\n");
			exit(1);
		}
		j++;
	}
	while (str[i])
	{
		if (ft_strlen_until(str[i], '\n') != line_size)
		{
			printf("WRONG LINE SIZE i = %d j = %d\n", i, j);
			exit(1);
		}
		j = 0;
		while (str[i][j])
		{
			if (j == 0 && str[i][j] != '1')
			{
				printf("NO 1 at begin of line : %d\n", i);
				exit(1);
			}
			j++;
		}
		if (j - 1 >= 0 && str[i][j - 1] != '1')
		{
			printf("NO 1 at end of line : %d\n", i);
			exit(1);
		}
		i++;
	}
	j = 0;
	if (i - 1 < 0)
	{
		printf("ONLY 1 line in your file pfff\n");
		exit(1);
	}
	while (str[i - 1][j])
	{
		if (str[i - 1][j] != '1')
		{
			printf("NOT ONLY 1 ON LAST LINE\n");
			exit(1);
		}
		j++;
	}
}

// char	ft_guardian(char *str)
// {
// 	int	i;
// 	int	k;
// 	int	truth;

// 	i = -1;
// 	while (str[++i] != '\n')
// 	{
// 		if (str[i] != '1')
// 			ft_sad(i);
// 	}
// 	truth = i;
// 	k = 0;
// 	while (str[i])
// 	{
// 		printf("%d\n", i);
// 		if (str[i] == '\n')
// 		{
// 			if (str[i + 1] != '1' || str[i - 1] != '1' || ((i) % truth) != k)
// 				ft_sad(i);
// 			k += 1;
// 			printf("truth = %d i = %d et k = %d\n", truth, i, k);
// 		}
// 		i++;
// 	}
// 	ft_remains(i, truth, k, str);
// 	return (1);
// }

char	ft_location(char *str, t_design *object)
{
	int	i;

	i = -1;
	object->player = 0;
	object->coin = 0;
	object->end = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == 'P')
			object->player++;
		if (str[i] == 'C')
			object->coin++;
		if (str[i] == 'E')
			object->end++;
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'P'
			&& str[i] != 'E' && str[i] != '\n')
			ft_sad(i);
	}
	if (object->player != 1 || object->end <= 0 || object->coin <= 0)
		ft_sad(i);
	return (1);
}

char	**map_read(int fd)
{
	int			i;
	char		**map;
	char		*str;
	char		*tmp;
	t_design	object;

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
	map = ft_split(tmp, '\n');
	ft_guardian(map);
	ft_location(tmp, &object);
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (map);
}
