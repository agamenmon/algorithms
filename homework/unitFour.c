/*
* function pointer
*
* source: https://www.learn-c.org/en/Function_Pointers
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *left, const void *right)
{
    return (*(int *)right - *(int *)left);
}

int main(void)
{
    int (*cmp) (const void *, const void *);
    cmp = &compare;

    int iArray[] = {1, 2, 3, 4, 5, 6, 7};

    /* sort the array */
    qsort(iArray, sizeof(iArray)/sizeof(*iArray), sizeof(*iArray), cmp);

    int c = 0;
    while(c < sizeof(iArray)/sizeof){
        /* code */
    }
    
    return 0;
}


/*
* Note: 
* I used the function pointer in some project and it really good. 
*  the function pointer can manage the source code and its more clear
*  if we have multiple function.
*  We can put all the function pointer into an array.
*/