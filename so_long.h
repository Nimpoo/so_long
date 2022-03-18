/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:29:27 by mayoub            #+#    #+#             */
/*   Updated: 2022/03/15 19:53:01 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_design{
	int	player;
	int	end;
	int	coin;
	int	vilain;
}t_design;

char	*ft_strdup(char *s1);
char	**ini_so_long(int fd);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		counter(const char *str, char c);
char	*duplicator(const char *str, int start, int end);
char	**ft_split(char *s, char c);
int		ft_solen(char *str, char a);
char	**map_read(int fd);

#endif
