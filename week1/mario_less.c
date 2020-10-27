#include <cs50.h>
#include <stdio.h>

/*
 * Author: Lionel Ngoubou
 * Purpose: Recreate the Super Mario pyramid.
 */

int main(void)
{
    int n;
    
    do
    {
        // prompt the user to enter an integer
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

// loop through the lines and print a space
// then a hash at each iteration

    for (int i = 0; i < n; i++)
    {
        // print the space characters
        for (int j = n - 1 - i; j > 0 ; j--)
        {
            printf(" ");
        }
        // print the hashes
        for (int k = i + 1; k > 0; k--)
        {
            printf("#");
        
        }
        printf("\n");
         
    }
    
}


