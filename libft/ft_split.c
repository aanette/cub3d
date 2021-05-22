/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:56:45 by aanette           #+#    #+#             */
/*   Updated: 2021/04/25 15:36:39 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_count(const char *str, char c)
{
	int		count;

	count = 0;
	if (!*str)
		return (0);
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static int	char_count(const char *str, char c, int i)
{
	int		count;

	count = 0;
	while (str[i] && str[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**frees(char const **s, int i)
{
	while (i > 0)
	{
		i--;
		free((void *)s[i]);
	}
	free(s);
	return (NULL);
}

static char	**ft_r(char const *s, char **s2, char c, int m)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < m)
	{
		k = 0;
		while (s[i] == c)
			i++;
		s2[j] = (char *) malloc(sizeof(char) * (char_count(s, c, i) + 1));
		if (!s2[j])
			return (frees((char const **) s2, j));
		while (s[i] && s[i] != c)
			s2[j][k++] = s[i++];
		s2[j][k] = '\0';
		j++;
	}
	s2[j] = NULL;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char	**s2;

	if (!s)
		return (0);
	s2 = (char **)malloc(sizeof(char *) * (str_count(s, c) + 1));
	if (!(s2))
		return (NULL);
	return (ft_r(s, s2, c, str_count(s, c)));
}
