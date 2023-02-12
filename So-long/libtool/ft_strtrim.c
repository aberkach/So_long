/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abberkac <abberkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:25:42 by abberkac          #+#    #+#             */
/*   Updated: 2022/11/19 03:47:33 by abberkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_first(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	check_last(char c, char *set)
{
	int	len;

	len = ft_strlen(set);
	len = len -1;
	while (len >= 0)
	{
		if (set[len] == c)
			return (1);
		len--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s1);
	while (check_first(s1[i], (char *)set))
		i++;
	j--;
	while (check_last(s1[j], (char *)set))
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
