#include "get_next_line.h"

//WOULDNT WORK BECAUSE
//i stays 1 because f1 is not returning anything
//https://en.wikipedia.org/wiki/Pure_function
//i and j are not the same

/*
void	f1(int j) //j is local variable. j ist formal argument
{
	j = 42;
	printf("adress of j in f1 = %d\n", &j);
}

int	main()
{
	int	i = 1; //i is local variable
	f1(i); //value of i is copied into variable j. i is actual argument
	printf("adress of i in main = %d\n", &i);
	printf("value of i in main %d\n", i);

	return 0;
}
*/

/*
//WOULD WORK
int	f1(int j){
	j = 42;
	return(j);
}

int	main(void){
	int	i = 1;
	//f1(i); - wouldnt work
	i = f1(i);
	printf("%d\n", i);

	return 0;
}
*/

/*
//WOULDNT WORK - SEE 1ST EXAMPLE
int	f1(int j){
	j = 42;
	return(j);
}

void f2(int x){
	x = x * 2;
}
int	main(void){
	int	i = 1;
	//f1(i); - wouldnt work
	i = f1(i);
	printf("%d\n", i);

	return 0;
}
*/

/*
//VOID WILL WORK - MEMORY ACCESS
int	f1(int j){
	j = 42;
	return(j);
}

void f2(int *x) //x - address of memory, CALL BY REFERENCE
//https://www.youtube.com/watch?v=zuegQmMdy8M&t=8s
//43:00
//create pointer and access to data (dereferencing) uses * sign
{
	*x *= 2;
}
int	main(void){
	int	i = 1;
	//f1(i); - wouldnt work
	i = f1(i);
	f2(&i); //call by reference (instead of value)
	printf("%d\n", i);

	return 0;
}
*/