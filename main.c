 #include <stdio.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <stdlib.h>

 int main()
{
	int fd = open("text.txt", O_RDONLY); 
	//create a buffer and give it a size of 100
	char *b = (char *) calloc(100000, sizeof(char));
	//static char b[100];
	read(fd, b, 12);
	printf("%s\n", b);
	close(fd);
	return 0;
}