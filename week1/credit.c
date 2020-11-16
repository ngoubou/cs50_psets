#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>  


/*
 * Author: Lionel Ngoubou
 * Purpose: Luhn’s Algorithm implementation : 
 Check if credit card number is valid.
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

    // convert input to char
    char str[12];
    sprintf(str, "%ld", card);

    if (strlen(str) == 15)
    {
        printf("AMEX\n");
    }
    else if (strlen(str) == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (strlen(str) == 13 || strlen(str) == 16)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
   


}
