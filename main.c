
/*
we must inform the operating system of our intentions with the 'open' function of the fcntl.h library. 
in this system call, we need to specify the path towards the file & 
the way in which we want to access it with flags.

the system sends a small non-negative integer called a file descriptor.
from now on, we use this fd to refer to the file, instead of its name.
our file might be assigned a number 3 or higher.

if we ask to open a file that doesn’t exist, or a file we don’t have 
the permission to open, fd is equal to -1
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

// Casting argc to quiet the compiler's warnings.
	(void)argc;
// Open the file given as an argument at program launch
	fd = open(argv[1], O_RDONLY);
// Initialize this variable to be able to use it in the following loop
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}

/* 
when we are done manipulating a file, we must de-reference the file descriptor 
with the close function of the unistd.h library
*/
