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

// At each line (iteration), I want n objects
// where n = height.
// These n objects are shared as follow :
// n = space + hash; 
// space = height - hash et hash = i + 1
// where i is the level we're at (starting at 0)

    for (int i = 0; i < height; i++)
    {
        // Print the space characters
        for (int space = height - 1 - i; space > 0 ; space--)
        {
            printf(" ");
        }
        // Print the hashes
        for (int hash = i + 1; hash > 0; hash--)
        {
            printf("#");

        }
        printf("\n");

    }

}


