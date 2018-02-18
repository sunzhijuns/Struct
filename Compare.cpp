//
// Created by sunzhijun on 18-2-18.
//
#include "Compare.h"

#define TEST_COMPARE_STRCMP
#ifdef TEST_COMPARE_STRCMP

#include <stdio.h>
#include <string.h>

int main ()
{
    char key[] = "apple";
    char buffer[7];
    do {
        printf ("Guess my favorite fruit? ");
        fflush (stdout);
        scanf ("%6s",buffer);
        printf("\n---%s---\n",buffer);
    } while (strcmp (key,buffer) != 0);
    puts ("Correct answer!");
    return 0;
}

#endif
