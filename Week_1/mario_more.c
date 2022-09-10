#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user then check if between ]1;8[
    int height;
    do
    {
        height = get_int("Height of pyramid: ");
    }
    while (height < 1 || height > 8);

    // Process: At each line we had a certain number of spaces (height - nb line), we add an # (nb hashes = nb line), we add a space for separation between the two pyramids then we add an # too (nb hashes = nb lines) and finaly go to new line.

    // Loop for moving through lines
    for (int line = 0; line < height; line++)
    {
        // Loop for adding spaces. As line nb goes up, nb of spaces needed decrease. Each loop -1 until no spaces required. We want line=0, 0 space. line=1, 1 space.
        for (int spaces = height - line - 1; spaces > 0; spaces--)
        {
            printf(" ");
        }
        // Now we add hashes. Nb of line = Nb of hashes. +1 because line nb start at 0 not 1.
        for (int hashes = 0; hashes < line + 1; hashes++)
        {
            printf("#");
        }
        //Seperator between pyramids
        printf("  ");
        // Loop for hashes other side
        for (int hashes = 0; hashes < line + 1; hashes++)
        {
            printf("#");
        }
        // Go to newline
        printf("\n");
    }
}