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
}
