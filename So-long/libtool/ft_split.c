/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abberkac <abberkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:31:22 by abberkac          #+#    #+#             */
/*   Updated: 2022/11/19 03:52:30 by abberkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			n++;
		}
	}
	return (n);
}

static int	word_len(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s && *s != c)
	{
		s++;
		count++;
	}
	return (count);
}

static char	**ft_free(char **str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free (str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	i;
	unsigned int	count;
	unsigned int	start;

	if (!s)
		return (0);
	i = 0;
	start = 0;
	count = count_word(s, c);
	str = (char **)malloc(sizeof(*str) * (count + 1));
	if (!str)
		return (0);
	str[count] = NULL;
	while (i < count)
	{
		while (s[start] && s[start] == c)
			start++;
		str[i] = ft_substr(s, start, word_len(s + start, c));
		if (!str[i])
			return (ft_free(str, i));
		i++;
		start = start + word_len(s + start, c);
	}
	return (str);
}
