/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:44:29 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/06/30 15:21:48 by dgoremyk         ###   ########.fr       */
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
	char buffer[BUFFER_SIZE + 1];
	char *ptr_n;
	int flag = 1;
	static char	*leftover;

	*line = ft_strnew(1);
	//while ((byte_was_read = read(fd, buffer, 10)))
	while (flag && (byte_was_read = read(fd, buffer, 10)))  //SIC!!! save and check for 0 double parentheses
	{
		buffer[byte_was_read] = '\0'; // NEEDED?
		if ((ptr_n = ft_strchr(buffer, '\n')))
		{
			*ptr_n = '\0';
			flag = 0;
		}
		buffer[byte_was_read] = '\0';
		*line = ft_strjoin(*line, buffer);
	} 
	return (0);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	//printf("fd: %d\n", fd);
	//printf("fd: %d\n", 3);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	close (fd);
	return (0);
}
