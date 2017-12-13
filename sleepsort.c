#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sleepsort.h"

int sleepsort(long* arr, long* ans)
{
	pthread_t threads[TOTAL_THREADS];
	pthread_attr_t attr;
	void* status;
	int error, i, ch;
	FILE *file;
	const char *filename = PATH;
	file = fopen( filename, "r+");

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	for(i = 0; i < TOTAL_THREADS; ++i)
	{
		error = pthread_create(&threads[i], &attr, sleeper, (void*)arr[i]);
		if(error)
		{
			printf("ERROR pthread_create() returned: %d \n",error);
			return(-1);
		}
	}

	// join-ing threads to see if there were any issues in 
	pthread_attr_destroy(&attr);
	for(i = 0; i < TOTAL_THREADS; ++i)
	{
		error = pthread_join(threads[i], &status);
		if(error)
		{
			printf("ERROR pthread_join() returned: %d \n",error);
			return(-1);
		}else if((long)status == -1){
			return(-1);
		}
	}

	// should check with `getc(file)) != EOF;` but I'm living on
	// the edge here
	i = 0;
	if(ans != NULL)
	{
		while(i < TOTAL_THREADS)
		{
			ch = fgetc(file);
			ans[i] = ch;
			++i;
		}
	}else{
		while(i < TOTAL_THREADS)
		{
			ch = fgetc(file);
			arr[i] = ch;
			++i;
		}
	}

	// closes the file and deletes all the contents
	fclose(fopen(filename, "w"));
	file = NULL;
	return 0;
}

void *sleeper(void* n)
{
	long length = (long)n;
	FILE *file;
	const char *filename = PATH;
	file = fopen( filename, "a");
	long result = -1;

	if( file == NULL ){
		fprintf(stderr, "fopen() failed with error number: %s\n", strerror((int)file));
		pthread_exit((void *) result);
	}

	if(length < 0){
		printf("What are you doin? Negative numbers in a thing that uses sleep???\nFor shame...\n");
		pthread_exit((void *) result);
	}

	// sleeps for `length` time, 
	sleep(length);
	fputc(length, file);
	fclose(file);
	file = NULL;
	result = 0;
	pthread_exit((void*)result);
}
