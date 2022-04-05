/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:29:27 by mayoub            #+#    #+#             */
/*   Updated: 2022/04/05 06:41:34 by mayoub           ###   ########.fr       */
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

typedef struct s_sprites{
	void	*ground;
	void	*wall;
	void	*exit;
	void	*coin;
	void	*player_front;
	void	*player_back;
	void	*player_left;
	void	*player_right;
	void	*vilain_front;
	void	*vilain_back;
	void	*vilain_left;
	void	*vilain_right;
}t_sprites;

typedef struct s_design{
	int	player;
	int	end;
	int	coin;
	int	vilain;
}t_design;

typedef struct s_location{
	int	x;
	int	y;
}t_location;

typedef struct s_position{
	char	p_player;
	int		p_end;
	int		p_coin;
	int		p_vilain;
}t_position;

typedef struct s_perimeter{
	int		height;
	int		lengh;
	char	**map;
}t_perimeter;

typedef struct s_var{
	int	i;
	int	j;
	int	d_x;
	int	d_y;
}t_var;

typedef struct s_game{
	void		*mlx;
	void		*win;
	t_perimeter	map;
	t_design	objects;
	t_sprites	img;
	t_var		var;
	t_location	loc;
	t_position	pos;
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
void	ft_graphic(t_game *all, void *mlx, void *win);
void	window(t_game *all);
void	ft_ini_sprites(t_game *all, void *mlx);
void	ini_variable(t_game *all);
void	backslash_n(t_game *all);
void	colle_image_wall(t_game *all, void *mlx, void *win);
void	colle_image_coin(t_game *all, void *mlx, void *win);
void	colle_image_exit(t_game *all, void *mlx, void *win);
void	colle_image_player(t_game *all, void *mlx, void *win);
void	colle_image_vilain(t_game *all, void *mlx, void *win);
int		tester(int i, t_game *all);

#endif
