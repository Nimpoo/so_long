/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:34:34 by mayoub            #+#    #+#             */
/*   Updated: 2022/04/08 06:08:20 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	counter(const char *str, char c)
// {
// 	int	i;
// 	int	trigger;

// 	i = 0;
// 	trigger = 0;
// 	if (!str)
// 		return (0);
// 	while (*str)
// 	{
// 		if (*str != c && trigger == 0)
// 		{
// 			trigger = 1;
// 			i++;
// 		}
// 		else if (*str == c)
// 			trigger = 0;
// 		str++;
// 	}
// 	return (i);
// }

// char	*duplicator(const char *str, int start, int end)
// {
// 	int		i;
// 	char	*word;

// 	i = 0;
// 	word = malloc((end - start + 1) * sizeof(char));
// 	if (!word || !str)
// 		return (0);
// 	while (start < end)
// 	{
// 		word[i] = str[start];
// 		i++;
// 		start++;
// 	}
// 	word[i] = '\0';
// 	return (word);
// }

// char	**ft_split(char *s, char c)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		trigger;
// 	char	**result;

// 	i = 0;
// 	j = 0;
// 	trigger = -1;
// 	result = malloc((counter(s, c) + 1) * sizeof(char *));
// 	if (!s || !result)
// 		return (0);
// 	while (i <= ft_strlen(s))
// 	{	
// 		if (s[i] != c && trigger < 0)
// 			trigger = i;
// 		else if ((s[i] == c || i == ft_strlen(s)) && trigger >= 0)
// 		{
// 			result[j] = duplicator(s, trigger, i);
// 			j++;
// 			trigger = -1;
// 		}
// 		i++;
// 	}
// 	result[j] = 0;
// 	return (result);
// }

/*size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/
int	ft_wrdcnt(char *s, char c)
{
	int	wrd;
	int	i;

	i = 0;
	wrd = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			wrd++;
		i++;
	}
	if (s[0] != '\0')
		wrd++;
	return (wrd);
}

char	*ft_getwrd(char *s, char c, int *i)
{
	char	*d;
	int		k;

	k = 0;
	d = (char *)malloc(sizeof(*d) * ft_strlen(s));
	if (!d)
		return (NULL);
	while (s[*i] && s[*i] != c)
	{
		d[k] = s[*i];
		k++;
		*i = *i + 1;
	}
	d[k] = '\0';
	while (s[*i] && s[*i] == c)
		*i = *i + 1;
	return (d);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		wrd_cnt;
	char	**str;

	i = 0;
	j = 0;
	wrd_cnt = ft_wrdcnt(s, c);
	str = (char **)malloc(sizeof(s) * (wrd_cnt + 1));
	if (!str)
		return (NULL);
	while (s[i] && s[i] == c)
		i++;
	while (j < wrd_cnt && s[i])
	{
		str[j] = ft_getwrd(s, c, &i);
		j++;
	}
	str[j] = NULL;
	return (str);
}
