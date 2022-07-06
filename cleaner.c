#include "get_next_line.h"

#include <stdio.h> //printf
#include <unistd.h> //close read write
#include <fcntl.h> //open
#include <stdlib.h> //malloc

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

int main()
{
	char *hold = "sdfjhg\nsfldkjh";
	// char *newstr = garbage_collector(str);
	char *newstr=  cleaner(hold);
	printf("%s\n", newstr);
	return (0);
}
