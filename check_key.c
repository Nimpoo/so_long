/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:57:07 by mayoub            #+#    #+#             */
/*   Updated: 2022/04/13 15:57:31 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_key(t_game *all, int key)
{
	if (key == UP)
		all->side.side_p = UP;
	if (key == DOWN)
		all->side.side_p = DOWN;
	if (key == LEFT)
		all->side.side_p = LEFT;
	if (key == RIGHT)
		all->side.side_p = RIGHT;
}
