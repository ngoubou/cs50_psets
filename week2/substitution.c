#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * Author: Lionel Ngoubou
 * Purpose: Substitution cipher implementation :
   a program that encrypts messages
 */

int main(int argc, string argv[])
{
    //printf("%lu\n", strlen(argv[1]));
    string alph = {"abcdefghijklmnopqrstuvwxyz"};

    // Handle lack of key and invalid length
    if (argv[1] == 0 || strlen(argv[1]) != 26)
    {
        printf("The key is either missing or is not 26 characters\n");
        return 1;
    }

    // Handle non alphabetical characters in key
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("The key must be alphabetical\n");
            return 1;
        }
    }
    // Handle duplicate letters in key
    int count = 0;
    for (int i = 0; i < 26 - 1; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                //printf("you da best bb\n");
                count++;
            }
        }
    }
    if (count > 0)
    {
        printf("There are repetitive characters in the key\n");
        return 1;
    }


    // Encrypt valid keys
    if (strlen(argv[1]) == 26)
    {
        string text = get_string("Gimme dat sauce: ");
        string arr[] = {text};
        printf("ciphertext: ");


        for (int i = 0; i < strlen(arr[0]); i++)
        {
            // Handle spaces, non-alphanumeric symbols and digits
            if (isspace(arr[0][i]) || !isalnum(arr[0][i]) || isdigit(arr[0][i]))
            {
                printf("%c", arr[0][i]);
            }

            for (int j = 0; j < strlen(alph); j++)
            {
                // Compare index of letter in key to the one in alphabet
                // print the letter that corresponds to the matching index in key
                if (arr[0][i] == alph[j])
                {
                    printf("%c", tolower(argv[1][j]));
                }
                // Handle majuscule letters
                else if (isupper(arr[0][i]))
                {
                    if (toupper(arr[0][i]) == toupper(alph[j]))
                    {
                        printf("%c", toupper(argv[1][j]));
                    }
                }

            }
        }
    }

    printf("\n");
    return 0;
}
