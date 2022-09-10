#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Points and letter of the alphabet
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int calculate_score(string word);


int main(void)
{
    // Input for both words
    string answer1 = get_string("Player 1: ");
    string answer2 = get_string("Player 2: ");

    // Int for score
    int score1 = calculate_score(answer1);
    int score2 = calculate_score(answer2);

    //Display winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
    
}

int calculate_score(string word)
{
    int score = 0;
    // Create a for loop to cycle through the words.
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Put all letter in uppercase
        word[i] = toupper(word[i]);
        char letter = word[i];
        for (int j = 0; letters[j]; j++)
        {
            if (word[i] == letters[j])
            {
                score += points[j];
            }
        }
    }
    return score;
}