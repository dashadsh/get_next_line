#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/*
int main()
{
//creates a "new" file if not exists
	int fd = open("new", O_RDWR | O_CREAT);
	close(fd);
	return 0;
}
*/

int main()
{
	int fd = open("text.txt", O_RDONLY);
	//create a buffer and give it a size of 100
	char *b = (char *) calloc(1, sizeof(char));
	//char b[100];
	read(fd, b, 500);
	printf("%s\n", b);
	close(fd);
	return 0;
}
