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


// char	*ft_strcpy(char *dest, char *src)
// {
// 	int i;

// 	i = 0;
// 	while (*(src + i))
// 	{
// 		*(dest + i) = *(src + i);
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

///////////////////////////////////////////////////////////////////////////
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

char *cleaner(char *hold)
{
	char	*line;
	int	i;

	i = 0;
	while (hold[i] && hold[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0); //free?
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
	// if (!hold)
	// {
	// 	free (hold);
	// 	return (0);
	// }
	garbage = (char *)malloc(sizeof(char) * (ft_strlen(hold) - i + 1));
	if (!garbage)
		return (0);
	i++;
	j = 0;
	while (hold[i])
		garbage[j++] = hold[i++];
	garbage[j] = '\0';
	// free(hold);
	return (garbage);
}

// char *garbage_collector(char *hold)
// {
// 	char	*garbage;
// 	char	*ptr_n;

// 	ptr_n = ft_strchr(hold, '\n');
// 	ft_strcpy(garbage, ++ptr_n);
// 	return (garbage);
// }

char *get_next_line(int fd)
{
	static char	*hold;
	char	*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	hold = malloc(1); //WHYYYYYYYYYYYYYYYYYY
	// if (!hold)
	// 		return (0);
	hold = reader(fd, hold);
	line = cleaner(hold);
	hold = garbage_collector(hold);
	return(line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text2.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	return (0);
}