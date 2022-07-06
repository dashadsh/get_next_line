#include "get_next_line.h"

#include <stdio.h> //printf
#include <unistd.h> //close read write
#include <fcntl.h> //open
#include <stdlib.h> //malloc

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstring == 0)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{	
			newstring[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (s2[j])
		newstring[i++] = s2[j++];
	newstring[i] = '\0';
	return (newstring);
}


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

int	main(void)
{
	int		fd;
	char	*line;

	line = malloc(1);
	line[0] = '\0';
	fd = open("text2.txt", O_RDONLY);
	line = reader(fd, line);
	printf("%s\n", line);
	line = reader(fd, line);
	close(fd);
	return (0);
}