/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:31:20 by mayoub            #+#    #+#             */
/*   Updated: 2022/04/22 15:37:23 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *all)
{
	int	i;

	i = 0;
	while (all->map.map[i])
		free(all->map.map[i++]);
	free(all->map.map[i]);
}

int	kill_window(t_game *all)
{
	free_map(all);
	exit(0);
}
