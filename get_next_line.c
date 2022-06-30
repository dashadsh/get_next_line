/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:44:29 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/06/30 13:55:49 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* man 2 read, find

lseek() is forbidden

read(), malloc, free()
static variables
open() - how to open files, access to their content

fd 10240

adding lines w strjoin

int	ft_check_eol
int	ft_check_eof
*/


char	*get_next_line(int fd, char **line) 
{
	int	byte_was_read;
	char buffer[10 + 1];
	*line = ft_strnew(1);
	while ((byte_was_read = read(fd, buffer, 10))) //SIC!!! save and check for 0 double parentheses
	{
		if (ft_strchr(buffer, '\n'))
			break ;
		buffer[byte_was_read] = '\0';
		*line = ft_strjoin(*line, buffer);
	} 
	return (0);
}

int	main(void)
{
	int		fd;
	char	*line;

	line = "0123456789";
	printf("init line: %s\n", line);
	fd = open("text.txt", O_RDONLY);
	//printf("fd: %d\n", fd);
	//printf("fd: %d\n", 3);
	get_next_line(fd, &line);
	printf("line after gnl: %s\n", line);
	close (fd);
	return (0);
}
