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
    

    // check if arg is null
    if (argv[1] == 0 || argc > 2) 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // handles non numeric key
   

    else
    {
        // if it's not a number
        // return 1 and exit
        int key =  atoi(argv[1]);

        if (key == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        else
        {
            string text = get_string("Gimme dat sauce: ");

            // i convert the input to an array so i can loop through
            string arr[] = {text};

            printf("ciphertext: ");
            for (int i = 0; i < strlen(arr[0]); i++)
            {
                // check if it's space or nonalphanum and print the same thing
                if (isspace(arr[0][i]) || !isalnum(arr[0][i]))
                {
                    printf("%c", arr[0][i]);
                }


                for (int j = 0; j < strlen(alph); j++)
                {

                    // if the characters are equals print the next one
                    if (arr[0][i] == alph[j])
                    {
                        // if j + key is between 26 & 50, iterate at the start
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
                    // if it's a maj put the next one to maj
                    else if (isupper(arr[0][i]))
                    {
                        if (toupper(arr[0][i]) == toupper(alph[j]))
                        {
                            printf("%c", toupper(alph[j + key]));
                        }
                    }

                }
            }

        }
    }
    printf("\n");
}
