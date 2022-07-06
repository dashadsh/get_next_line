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
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
		newstr[i++] = s2[j++];
	//free(s2); //why doesnt work
	newstr[i] = '\0';
	// free(s1);
	return (newstr);
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
		// if (rd == -1)
		// {
		// 	free(tmp);
		// 	return (0);
		// }
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

	close(fd);
	return (0);
}