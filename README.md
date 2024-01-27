# C tool to count amount of memory allocated by program using all mallocs.

## Instructions:

Clone/Fork repository.

Compile malloc.c into a shared object:
gcc -o malloc.so -shared -fPIC -ldl malloc.c

Use LD_PRELOAD with any program, seq in this example:
LD_PRELOAD=./malloc.so seq 1 5
