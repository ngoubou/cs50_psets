#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


/*
 * Author: Lionel Ngoubou
 * Purpose: Luhn’s Algorithm implementation :
 Check if credit card number is valid.
 */
/* just to make it clear, i know by the time of writing this
how bad my code is; but as much as i'm sorry, this is needed*/

int main(void)
{
    // credit card 1st characters
    char arr[15] = "434375152535455";
    char dig[2] = "09";

    long input;

    // prompt the user to enter a positive float;
    // if he fails to, re-prompt him for a valid input
    do
    {
        input = get_long("Number: ");
    }
    while (input < 0);
    long x = input;

    // luhn's algo (very dirty)
    int c = 0;
    int f = 0;
    while (input)
    {
        int d = input % 10;
        input /= 10;
        int a = input % 10;
        int b = a * 2;
        input /= 10;
        c += b;
        f += d;
    }

    int g = f + c;
    // convert g to char
    char gg[3];
    sprintf(gg, "%i", g);


    // convert input to char
    char card[16];
    sprintf(card, "%ld", x);

    // VISA
    printf("%s\n", gg);
    if ((strlen(card) == 13 || strlen(card) == 16) && (card[0] == arr[0])
    && (gg[1] == dig[0] || gg[1] == dig[1]))
    {
        printf("VISA\n");
    }

    // AMEX
    else if (strlen(card) == 15 && (((card[0] == arr[1]) && (card[1] == arr[2])) ||
                                    ((card[0] == arr[3]) && (card[1] == arr[4])))
                                    && (gg[1] == dig[0] || gg[1] == dig[1]))
    {
        printf("AMEX\n");
    }

    // MASTERCARD
    else if (strlen(card) == 16 && (((card[0] == arr[5]) && (card[1] == arr[6])) ||
                                    ((card[0] == arr[7]) && (card[1] == arr[8])) ||
                                    ((card[0] == arr[9]) && (card[1] == arr[10])) ||
                                    ((card[0] == arr[11]) && (card[1] == arr[12])) ||
                                    ((card[0] == arr[13]) && (card[1] == arr[14])))
                                    && (gg[1] == dig[0] || gg[1] == dig[1]))
    {
        printf("MASTERCARD\n");
    }

    else
    {
        printf("INVALID\n");
    }

}

