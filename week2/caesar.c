#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * Author: Lionel Ngoubou
 * Purpose: Caesar’s cipher implementation :
   a program that encrypts messages
 */


int main(int argc, string argv[])
{
    string alph = {"abcdefghijklmnopqrstuvwxyz"};

    if (argv[1] == 0 || argc > 2) // check if arg is null
    {
        printf("Usage: ./caesar key");
    }

    else
    {
        int key =  atoi(argv[1]);

        if (key == 0)
        {
            printf("Usage: ./caesar key");
        }

        else
        {
            string text = get_string("Gimme dat sauce: ");

            //convert the input to an array so i can loop through
            string arr[] = {text};

            printf("ciphertext: ");
            for (int i = 0; i < strlen(arr[0]); i++)
            {
                for (int j = 0; j < strlen(alph); j++)
                {
                    if (arr[0][i] == alph[j])
                    {
                        printf("%c", alph[j + key]);
                    }
                }
            }

        }
    }
    printf("\n");
}
