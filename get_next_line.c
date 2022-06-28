#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "get_next_line.h"

char *get_smth(int fd)
{
	char *buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	
	int amount = read(fd, buffer, 9);
	printf("amount to read 1st time: %d\n", amount);
	printf("%s\n", buffer); //d?

	amount = read(fd, buffer, 20);
	printf("amount to read 2nd time: %d\n", amount);
	printf("%s\n", buffer); //d?

	return (buffer); // NOT RETURN NULL!!!
}

int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *result = get_smth(fd);
	printf("main: %s\n", result);

	close(fd);
	return 0;
}
