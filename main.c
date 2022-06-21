 #include <stdio.h>
 
 int main()
{
	//FILE *fd = fopen("text.txt", "r");
	fd = open("text.txt", O_RDONLY); 
	//create a buffer and give it a size of 100
	char *c = (char *) calloc(100, sizeof(char));

	read("text.txt", )
	fclose(fd);
	return 0;
}