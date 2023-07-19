/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihemayoub <sihemayoub@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:57:07 by mayoub            #+#    #+#             */
/*   Updated: 2023/07/19 17:16:49 by sihemayoub       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
