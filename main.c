#include <stdio.h>

#include "sleepsort.h"

void print_array(long *arr)
{
	int i = 0;
	for(i = 0; i < TOTAL_THREADS; ++i)
		printf("%ld ", arr[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	int flag = 0;
	long array[TOTAL_THREADS]  = {3,3,2,2,3};
	long answer[TOTAL_THREADS] = {0,0,0,0,0};

	printf("The unsorted array is: ");
	print_array(array);

	flag = sleepsort(array, answer);

	if(flag)
	{
		printf("Sleepsort exited with an error \n");
		return(-1);
	}


	printf("The sorted array is: ");
	print_array(answer);

	return 0;
}