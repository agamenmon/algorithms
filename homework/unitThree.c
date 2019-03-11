/*
* Recursion occurs
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_FIRST_NUMBER    1
#define DEFAULT_SECOND_NUMBER   1

/*
* multiple_number(numberAdd, times)
*
* This function will performance mutiple time until the times reach to 1
*   and the numberAdd will be added and based on times performace.
*/
unsigned int multiple_number(unsigned int numberAdd, unsigned int times)
{
    unsigned int result;

    if(times > 1)
    {
        /* reduce times and add the numberAdd multiple */
        times--;
        result = numberAdd + multiple_number(numberAdd, times);
    }
    else if(times == 1)
    {
        /* return the value if times is only ONE*/
        result = numberAdd;
    }
    else
    {
        /* Catch scenario when times is ZERO */
        result = 0;
    }
    
    return result;
}

/* printf usage command */
void command_help(void)
{
    printf("[HELP]\n\n");
    printf("./unitThree,o [firstNumber] [secondNumber]\n");
}

/* The main program */
int main(char argc, char **argv)
{
    /* input value x and y */
    unsigned int firstNumber;
    unsigned int secondNumber;

#define MAX_INPUT_NUMBER 3
    if(argc < MAX_INPUT_NUMBER)
    {
        /* check the input value for helping information */
        if(!strcmp(argv[1], "help") || !strcmp(argv[1], "-h"))
        {
            command_help();
            return 0;
        }

        printf("[ERROR] input the firstNumber and the secondNumer\n");
        printf("The first number and the secondNumber is default value: ONE\n");

        /* set the default value */
        firstNumber = DEFAULT_FIRST_NUMBER;
        secondNumber = DEFAULT_SECOND_NUMBER;
        goto caluatorNumber;
    }

    /* input the value */
#define POINTER_FIRST_NUMER   1
#define POINTER_SECOND_NUMBER 2
    firstNumber = strtol(argv[POINTER_FIRST_NUMER], NULL, 0);
    secondNumber = strtol(argv[POINTER_SECOND_NUMBER], NULL, 0);

    /* check the input value */
    if((!firstNumber) || (!secondNumber))
    {
        printf("The result is Zero, One of the input number is Zero");
        return 0;
    }

caluatorNumber:
    printf("The multiple value x and y is: %d\n", multiple_number(firstNumber, secondNumber));

    /* this function called for console to stop and preview the result */
    //system("pause");

    return 0;
}

/*
* Build this program
* gcc unitThree.c -o unitThree.o
* ./unitThree.o to excute the program
*/