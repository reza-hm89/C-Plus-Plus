#include <stdio.h>
#define MAX 10
int main()
{
    #if MAX > 99
     printf("compiled for array...\n");
    #else
     printf("compiled for small array");
    #endif
    return 0;
}

