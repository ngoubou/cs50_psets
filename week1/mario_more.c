#include <cs50.h>
#include <stdio.h>

/*
 * Author: Lionel Ngoubou
 * Purpose: Recreate the Super Mario adjacent pyramids.
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
        // Print the space
        for (int space = height - 1 - i; space > 0 ; space--)
        {
            printf(" ");
        }
        // Print the hash
        for (int hash = i + 1; hash > 0; hash--)
        {
            printf("#");

        }
        // Print the in-between space twice
        for (int j = 0; j < 2; j++)
        {
            printf(" ");
        }
        // Print the 2nd pyramid
        for (int pyr = i + 1; pyr > 0; pyr--)
        {
            printf("#");
        }
        
        printf("\n");

    }

}
