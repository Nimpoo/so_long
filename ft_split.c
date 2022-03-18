/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:34:34 by mayoub            #+#    #+#             */
/*   Updated: 2022/02/15 03:29:09 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	counter(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

char	*duplicator(const char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word || !str)
		return (0);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	j;
	int		trigger;
	char	**result;

	i = 0;
	j = 0;
	trigger = -1;
	result = malloc((counter(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (0);
	while (i <= ft_strlen(s))
	{	
		if (s[i] != c && trigger < 0)
			trigger = i;
		else if ((s[i] == c || i == ft_strlen(s)) && trigger >= 0)
		{
			result[j] = duplicator(s, trigger, i);
			j++;
			trigger = -1;
		}
		i++;
	}
	result[j] = 0;
	return (result);
}
