# Sleepsort

A sleepsort implementation with threading in c. I have'nt done much in c in a while since college,
so I thought I should try todo something goofy. I know it could have been less involved if I just
used `fork()`, but where's the fun in that??

## System

Should run on most systems with gcc installed. I wrote this on a mac and haven't really checked anything
else.

## How to Run

1. Download all the files to whatever directory you want.
2. Make an empty textfile and save it in that directory.
3. Update the `#define PATH` to the full path of the text file.
4. Update `main.c` however you want.
    1. make sure to update the `#define TOTAL_THREADS` to the number of elements in the array.
5. In terminal, `cd` to that directory and type `make`.
6. Type `./foo` to run the program


## Warning

There's ***technically*** no maximum of the number of threads that can be made by pthread, but don't 
make your array **too** big. I'd say < 100 with a max element < 10 for sanity's sake.

## Acknowledgments

* [POSIX Threads Programming] (https://computing.llnl.gov/tutorials/pthreads/) - Helped me to remember how to thread!

## Notes

This is my first project here so please feel free to tell me if I'm doing anything wrong. I don't know why someone would use 
this in a project, but feel free just shout me out!


