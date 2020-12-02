#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/*
 * Author: Lionel Ngoubou
 * Purpose: Caesar’s cipher implementation :
   a program that encrypts messages
 */

const int K = 1;

int main(void)
{
    string alph = {"abcdefghijklmnopqrstuvwxyz"};
  
    string text = get_string("Gimme dat sauce: ");  
    // i convert the input to an array so i can loop through
    string arr[] = {text};
    
    for (int i = 0; i < strlen(arr[0]); i++)
    {
        for (int j = 0; j < strlen(alph); j++)
        {
            if (arr[0][i] == alph[j])
            {
                printf("%c", alph[j + K]);
            }
        }
    }
    printf("\n");
 
}    
