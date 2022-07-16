/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:02:23 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/07/16 19:47:36 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*reader(int fd, char *hold)
{
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && (!ft_newline_found(hold)))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		hold = ft_strjoin(hold, buffer);
	}
	free(buffer);
	return (hold);
}

char	*cleaner(char *hold)
{
	char	*line;
	int	i;

	i = 0;
	if (!hold[i]) // don't free //not a "if (!hold)"
		return (NULL);
	while (hold[i] && hold[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (hold[i] && hold[i] != '\n')
	{
		line[i] = hold[i];
		i++;
	}
	if (hold[i] == '\n')
	{
		line[i] = hold[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*garbage_collector(char *hold)
{
	char	*garbage;
	int		i;
	int		j;

	i = 0;
	while (hold[i] && hold[i] != '\n')
		i++;
	if (!hold[i])
	{
		free (hold);
		return (NULL);
	}
	garbage = malloc((ft_strlen(hold) - i + 1) * sizeof(char));
	if (!garbage)
		return (NULL);
	i++;
	j = 0;
	while (hold[i])
		garbage[j++] = hold[i++];
	garbage[j] = '\0';
	free(hold);
	return (garbage);
}

char	*get_next_line(int fd)
{
	static char	*hold[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	hold[fd] = reader(fd, hold[fd]);
	if (!hold[fd])
	{
		//free (hold[fd]);
		return (NULL);
	}
	line = cleaner(hold[fd]);
	hold[fd] = garbage_collector(hold[fd]);
	return (line);
}
