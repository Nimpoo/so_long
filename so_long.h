/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:29:27 by mayoub            #+#    #+#             */
/*   Updated: 2022/03/27 11:15:08 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_design{
	int	player;
	int	end;
	int	coin;
	int	vilain;
}t_design;

typedef struct s_perimeter{
	int	height;
	int	lengh;
}t_perimeter;

typedef struct s_game
{
	t_perimeter	map;
	t_design	objects;
}t_game;

char	*ft_strdup(char *s1);
char	**ini_so_long(int fd, t_game *all);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		counter(const char *str, char c);
char	*duplicator(const char *str, int start, int end);
char	**ft_split(char *s, char c);
char	**map_read(int fd, t_game *all);
int		ft_lengh_height(char *str, t_game *all);
int		ft_sad(int i);
void	window(t_game *all);

#endif
