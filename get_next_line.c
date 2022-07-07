/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:02:23 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/07/07 12:10:09 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reader(int fd, char *hold)
{
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	bytes_read = 1;
	while (bytes_read != 0 && (!ft_strchr(hold, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (0);
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
	if (!hold) ///NEEDED??????
		return (NULL);
	while (hold[i] && hold[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
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

char	*garbage_collector(char *hold)
{
	char	*garbage;
	int		i;
	int		j;

	i = 0;
	while (hold[i] && hold[i] != '\n')
		i++;
	if (!hold[i]) //NEEDED?????
	{
		free (hold);
		return (NULL);
	}
	garbage = malloc((ft_strlen(hold) - i + 1) * sizeof(char));
	if (!garbage)
		return (0);
	i++;
	j = 0;
	while (hold[i])
		garbage[j++] = hold[i++];
	garbage[j] = '\0';
	free(hold); //not for single function, only LATER in program!!!
	return (garbage);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	hold = malloc(1);
	hold[0] = '\0';
	hold = reader(fd, hold);
	if (!hold)
		return(0);
	line = cleaner(hold);
	hold = garbage_collector(hold);
	return(line);
}


int	main(void)
{
	int		fd;
	char	*file;

	fd = open("text.txt", O_RDONLY);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	file = get_next_line(fd);
	printf("%s", file);
	free(file);
	close(fd);
	return (0);
}
