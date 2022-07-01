#include "get_next_line.h"

char *get_smth(int fd)
{
	char *buffer;
	int result;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	result = read(fd, buffer, BUFFER_SIZE);
	if (result == -1)
		printf("result error: %d\n", result);
	if (result == 0)
		printf("EOF. ret: %d\n", result);
	if (result > 0)
		printf("amt. of bytes read: %d\n", result);
	printf("read: %s\n", buffer);
	return (0); // ???????? or buffer?
}

int main(void)
{
	int fd;
	char *result;

	fd = open("text.txt", O_RDONLY);
    if (fd == -1)
		printf("file opening error: %d \n", fd);
	if (fd >= 0)
		printf("fd opened: %d\n", fd); 
	result = get_smth(fd);
	close(fd);
	return (0);
}
