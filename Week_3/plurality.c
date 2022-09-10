// Program that asks voter to insert the name of their candidate, counts it and prints the winner

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max nb of candidates
#define MAX 9

// Create a struct for candidate with name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Create an Array of candidates
candidate candidates[MAX];

// Var to count nb of candidates
int candidate_count = 0;

// Declare prototypes of future functions
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidates ...]\n");
        return 1;
    }
    // Assign nb of candidates 
    candidate_count = argc - 1;
    // Check how many candidates
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n",MAX);
        return 2;
    }
    // For each "candidate_count" we create a "profile" with name and votes
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of votes: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check if vote invalid
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    // Display winner
    print_winner();
}

bool vote(string name)
{
    // Check if voted names == candidates, if yes increase their votes.
    for (int i = 0, n = candidate_count; i < n; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{  
    // Keep track of candidates with most votes
    int greatest = 0;
    for (int i = 0, n = candidate_count; i < n; i++)
    {
        if (candidates[i].votes >  greatest)
        {
            greatest = candidates[i].votes;
        }
    }

    // Print the one with most votes
    for (int i = 0, n = candidate_count; i < n; i++)
    {
        if (greatest == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}