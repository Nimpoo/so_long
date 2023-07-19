/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihemayoub <sihemayoub@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:29:27 by mayoub            #+#    #+#             */
/*   Updated: 2023/07/19 21:30:27 by sihemayoub       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 0x35

# define TILE 64

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"

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

typedef struct s_cord{
	int	x;
	int	y;
}t_cord;

typedef struct s_cord_v{
	int	x;
	int	y;
}t_cord_v;

typedef struct s_position{
	t_cord		p_player;
	int			p_end;
	int			p_coin;
	t_cord_v	p_vilain;
}t_position;

typedef struct s_perimeter{
	int		height;
	int		lengh;
	char	**map;
}t_perimeter;

typedef struct s_var{
	int	i;
	int	j;
	int	v_i;
	int	v_j;
	int	d_x;
	int	d_y;
}t_var;

typedef struct s_side{
	int	side_p;
	int	side_v;
}t_side;

typedef struct s_game{
	void		*mlx;
	void		*win;
	int			steps;
	t_side		side;
	t_perimeter	map;
	t_design	objects;
	t_sprites	img;
	t_var		var;
	t_location	loc;
	t_position	pos;
	int			end_game;
}t_game;

char	*ft_strdup(char *s1);
void	ini_so_long(int fd, t_game *all);
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

void	ft_graphic(t_game *all);
void	window(t_game *all);
void	ft_ini_sprites(t_game *all);
void	ini_variable(t_game *all);
void	backslash_n(t_game *all);

void	colle_image_wall(t_game *all);
void	colle_image_coin(t_game *all);
void	colle_image_exit(t_game *all);
void	colle_image_player(t_game *all);
void	colle_image_vilain(t_game *all);

void	ini_mlx(t_game *all);

int		deplacement(int i, t_game *all);
void	check_key(t_game *all, int key);

int		ft_refresh(t_game *all);
int		kill_window(t_game *all);
char	*ft_itoa(int n);
void	put_steps(t_game *all);
int		ft_check_wall(t_game *all, int col, int line);

void	vilains_pos(t_game *all);
void	deplacement_vilain(int col, int line, t_game *all);
void	killed_by_vilain(t_game *all);

void	free_map(t_game *all);

#endif
