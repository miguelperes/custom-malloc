#include "mymemory.h"

int main()
{
    int *a = (int *)mymalloc(sizeof(int));
    myfree(a);
    return 0;
}