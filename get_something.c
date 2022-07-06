#include "get_next_line.h"

char	*get_smth(int fd)
{
	int	bytes_read;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		printf("error: %d\n", bytes_read);
	if (bytes_read == 0)
		printf("EOF: %d\n", bytes_read);
	if (bytes_read > 0)
		printf("bytes read: %d\n", bytes_read);
	printf("read: %s\n", buffer);
	return (0);
}

int main(void)
{
	int fd;
	char *something;

	fd = open("text2.txt", O_RDONLY);
	if (fd == -1)
		printf("file opening error: %d \n", fd);
	if (fd >= 0)
		printf("fd opened: %d\n", fd);
	printf("\n");
	something = get_smth(fd);
	printf("\n");
	something = get_smth(fd);
	printf("\n");
	something = get_smth(fd);
	close(fd);
	return (0);
}
