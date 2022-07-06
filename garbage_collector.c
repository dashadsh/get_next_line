#include "get_next_line.h"

#include <stdio.h> //printf
#include <unistd.h> //close read write
#include <fcntl.h> //open
#include <stdlib.h> //malloc

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

// char	*ft_strchr(char *s, int c)
// {
// 	int		i;

// 	i = 0;
// 	while (s[i] && s[i] != (char)c)
// 		i++;
// 	if (s[i] == (char)c)
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

// char *garbage_collector(char *hold)
// {
// 	char	*garbage;
// 	char	*ptr_n;

// 	ptr_n = ft_strchr(hold, '\n');
// 	ptr_n++;
// 	ft_strcpy(garbage, ptr_n);
// 	return (garbage);
// }

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

int main()
{
	char *hold = "sdfjhg\nsfldkjh";
	// char *newstr = garbage_collector(str);
	char *newstr=  garbage_collector(hold);
	printf("%s\n", newstr);
	return (0);
}