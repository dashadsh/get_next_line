/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:44:29 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/06/28 11:32:15 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*get_next_line(int fd)
{
	size_t	buffer;
	ssize_t	bytes_read;
	char	line;
	char	
	buffer = (char *)malloc(BUFFER_SIZE); 
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	
	
	
}