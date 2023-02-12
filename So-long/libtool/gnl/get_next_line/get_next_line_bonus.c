/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abberkac <abberkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:29:33 by abberkac          #+#    #+#             */
/*   Updated: 2022/12/11 16:10:48 by abberkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_get_next(char *buffer)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	rest = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		rest[j++] = buffer[i++];
	rest[j] = '\0';
	free(buffer);
	return (rest);
}

static char	*read_line(int fd, char *result)
{
	char	*buffer;
	int		byte_readed;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	byte_readed = 1;
	while (byte_readed && !ft_strchr(result, '\n'))
	{
		byte_readed = read(fd, buffer, BUFFER_SIZE);
		if (byte_readed < 0)
		{
			free(result);
			free(buffer);
			return (NULL);
		}
		buffer[byte_readed] = '\0';
		result = strjoin(result, buffer);
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_get_next(buffer[fd]);
	return (line);
}

