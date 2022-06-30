/* CALL BY REFERENCE " */

//int because 3 return values:
//1
//0 if read and reached EOF 
//-1 if erroe
#include "get_next_line.h"

//*line will just create a copy of value in a local variable
//line - char
//*line - line
//**line - address of line
char	*get_next_line(int fd, char **line) // char	*get_next_line(int fd, *line) 
{
	return (0);
}

int	main(void)
{
char *line;

//get_next_line(4, line);
while(get_next_line(4, &line))

	eturn 0;
}