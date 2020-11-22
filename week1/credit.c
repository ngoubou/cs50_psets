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
    // credit card 1st characters
    char arr[15] = "434375152535455";

    long input;

    // prompt the user to enter a positive float;
    // if he fails to, re-prompt him for a valid input
    do
    {
        input = get_long("Number: ");
    }
    while (input < 0);

    // convert input to char
    char card[12];
    sprintf(card, "%ld", input);

    // VISA
    if ((strlen(card) == 13 || strlen(card) == 16) && (card[0] == arr[0]))
    {
        printf("VISA\n");
    }
    
    // AMEX
    else if (strlen(card) == 13 && (((card[0] == arr[1]) && (card[1] == arr[2])) || 
                                    ((card[0] == arr[3]) && (card[1] == arr[4]))))
    {
        printf("AMEX\n");
    }
    
    // MASTERCARD
    else if (strlen(card) == 16 && (((card[0] == arr[5]) && (card[1] == arr[6])) ||
                                    ((card[0] == arr[7]) && (card[1] == arr[8])) ||
                                    ((card[0] == arr[9]) && (card[1] == arr[10])) ||
                                    ((card[0] == arr[11]) && (card[1] == arr[12])) ||
                                    ((card[0] == arr[13]) && (card[1] == arr[14]))))
    {
        printf("MASTERCARD\n");
    }
    
    else
    {
        printf("INVALID\n");
    }
  
} 


