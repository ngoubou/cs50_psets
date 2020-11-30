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
        for (int space = height - 1 - i; space > 0 ; space--)
        {
            printf(" ");
        }
        // print the hashes
        for (int hash = i + 1; hash > 0; hash--)
        {
            printf("#");

        }
        // print the in-between space
        for (int j = 0; j < 2; j++)
        {
            printf(" ");
        }
        // print the 2nd pyramid
        for (int pyr = i + 1; pyr > 0; pyr--)
        {
            printf("#");
        }
        
        printf("\n");

    }

}
