#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int counter = 0;
	int		fd;
	char	*file;
	
	fd = open("text.txt", O_RDONLY);
	while (counter <= 10)
	{
		file = get_next_line(fd);
		printf("%s", file);
		counter++;
	}
	free(file);
	close(fd);
	return (0);
}
