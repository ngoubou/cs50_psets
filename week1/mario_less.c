#include <cs50.h>
#include <stdio.h>

/*
 * Author: Lionel Ngoubou
 * Purpose: Recreate the Super Mario pyramid.
 */

int main(void)
{
    int height;

    do
    {
        // prompt the user to enter an integer
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

// at each line (iteration) i want n objects
// these n objects are shared as follow
// n - i - 1 spaces and the rest are hashes
// where i is the level we're at (starting at 0)

    for (int i = 0; i < height; i++)
    {
        // print the space characters
        for (int j = height - 1 - i; j > 0 ; j--)
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


