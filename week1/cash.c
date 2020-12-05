#include <cs50.h>
#include <stdio.h>

/*
 * Author: Lionel Ngoubou
 * Purpose: Recreate the Super Mario right-aligned pyramid.
 */

int main(void)
{
    int height;

    do
    {
        // Prompt the user to enter an integer
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);


    for (int i = 0; i < height; i++)
    {
        // Print the space characters
        for (int j = height - 1 - i; j > 0 ; j--)
        {
            printf(" ");
        }
        // Print the hashes
        for (int k = i + 1; k > 0; k--)
        {
            printf("#");

        }
        printf("\n");

    }

}


