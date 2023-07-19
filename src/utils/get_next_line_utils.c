/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihemayoub <sihemayoub@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 03:27:54 by mayoub            #+#    #+#             */
/*   Updated: 2023/07/19 21:17:03 by sihemayoub       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

size_t	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if ((char)c == 0)
		return (s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	n;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	n = 0;
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[n])
	{
		str[i + n] = s2[n];
		n++;
	}
	str[i + n] = 0;
	return (str);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*s2;

	s2 = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
