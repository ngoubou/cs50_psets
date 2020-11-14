#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>  


/*
 * Author: Lionel Ngoubou
 * Purpose: Check if a credit card numbers are valid.
 */

int main(void)
{
    long card;

    // prompt the user to enter a positive float; 
    // if he fails to, re-prompt him for a valid input
    do
    {
        card = get_long("Number: ");
    }
    while (card <= 0);

    // convert int to char
    char str[12];
    sprintf(str, "%ld", card);

    // count number of characters in the string
    if (strlen(str) < 13 || strlen(str) > 16) 
    {
        printf("INVALID\n");
    }
   


}

