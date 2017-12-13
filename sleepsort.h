/***********************************************************************
 *
 *	Author		: Anderew
 *
 *	File		: sleepsort.h 	- implimentation using threads
 *
 *	Description : I haven't done anything with threading since my junior 
 *				  year of college, so why not do it for the stupidest 
 * 				  reasons?
 *	
 ************************************************************************/

#ifndef SLEEPSORT_INCLUDED
#define SLEEPSORT_INCLUDED

//
// macros
#define TOTAL_THREADS 5			 // number of threads/ number of elements in the array
#define PATH "path_to_text_file" // insert the path to your text file here

/***********************************************************************
 *
 *	Function	: sleepsort
 *
 *	Description : Implement of sleepsort using threads. I saw a version
 *				  using fork(), but I wanted to 1 practice multithreading
 *				  and 2 
 *	
 *	Inputs 		:	arr - the unsorted or sorted array of type long
 *					ans - the array that holds the sorted array or 
 *						  NULL. If it is NULL, then
 *						  then it will update arr.
 * 
 *	Outputs 	:	-1 for any error, 0 success
 *
 ************************************************************************/
int sleepsort(long* arr, long* ans);

/***********************************************************************
 *
 *	Function	: sleeper
 *
 *	Description : Function called when the thread is created. Super Cool/
 *	
 *	Inputs 		:	n - void ptr pointing to an element of an array
 * 
 *	Outputs 	:	a void pointer. Points to -1 err, 0 success
 *
 ************************************************************************/
void *sleeper(void* n);

#endif