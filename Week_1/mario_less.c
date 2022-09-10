// Draws a pyramid using recursion

#include <cs50.h>
#include <stdio.h>

// We have to declare in advance the function we'll use. Define it later.
void draw(int n);

int main(void)
{
    // Get height of pyramid
    int height = get_int("Height: ");

    draw(height);
}


// The function is of type void because it won't return a value. It performs a task.
void draw(int n)
{
    // Var i represents the number of lines
    for (int i = 0; i < n; i++)
    {
        // Var j represents the number of spaces. As number of lines increase, the number of spaces decrease.
        for (int j = n - i; j > 0; j--)
        {
            printf(" ");
        }
        // Var j represents the number of # to add after we added the spaces in previous loop. We had to add +1 to var l so that we have a # at the first line because i start at 0
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}