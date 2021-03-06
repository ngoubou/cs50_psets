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

    // Check if there is more than 1 key or if it's null
    if (argv[1] == 0 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Handle non numeric key
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }

    //  Encrypt valid numeric keys
    if (argv[1] > 0)
    {
        int key =  atoi(argv[1]);

        // If it's not a number, exit
        if (key == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        else
        {
            string text = get_string("Gimme dat sauce: ");

            // Text to print before the output
            printf("ciphertext: ");

            for (int i = 0; i < strlen(text); i++)
            {
                // Handle spaces and non-alphanumeric symbols
                if (isspace(text[i]) || !isalnum(text[i]))
                {
                    printf("%c", text[i]);
                }

                for (int j = 0; j < strlen(alph); j++)
                {
                    // If the characters are equals print the next one in the alphabet
                    if (text[i] == alph[j])
                    {
                        // Cipher algorithm: ci = (pi + k) % 26
                        // If j + key is between 26 & 50, iterate at the start
                        if (j + key > 25 && j + key < 51)
                        {
                            printf("%c", alph[j + key - 26]);
                        }
                        else if (j + key > 50)
                        {
                            printf("%c", alph[(j + key - 26) % 26]);
                        }
                        else
                        {
                            printf("%c", alph[j + key]);
                        }
                    }

                    // Handle majuscule characters
                    // If it's a maj put the next one to maj
                    else if (isupper(text[i]))
                    {
                        if (toupper(text[i]) == toupper(alph[j]))
                        {
                            printf("%c", toupper(alph[j + key]));
                        }
                    }

                }
            }

        }
    }
    printf("\n");
    return 0;
}
