#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Note:
* This program doesnt finish.
* 
* I found some error this program:
*   - The character is duplicated on integer array.
*   - Need the other solution.
* => I will rewrite this program in another time.
*/

/* found the character in string */
int main(char argc, char **argv)
{
    char *inputString = "AAJKSHDASD";
    int count = 0;
    int result[100] = {0}; /* FIXME: Shouldnt have 100 element here, it must based on the strlen of input string */
    int temper = 0;
    for(count = 0; count < strlen(inputString); count++)
    {
        /* this should be change to char pointer */
        char scanCharacter = inputString[count];

        printf("%c, %d\n", scanCharacter, result[count]);

        for(temper = 0; temper < strlen(inputString); temper ++)
        {
            if(temper != count)
            {
                /* this string need to erase the element was scan to avoid the duplicate */
                if(scanCharacter == inputString[temper])
                {
                    result[count]++;
                }
            }
        }
    }
    /* printf the result counting the element duplicate */
    for(count = 0; count < strlen(inputString); count++)
    {
        printf("%d\n", result[count]);
    }
    return 0;
}

/*
* Build the program by the command below:
* gcc unitOne.c -o unitOne.o
*
* Run the program built by command below
* ./unitOne.o
* Note: Im using the ubuntu to compile and run this program.
*/