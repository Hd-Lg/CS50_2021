#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// We get a 26-characters key. 'A' should be converted in the first letter of the key. 'B' in the second letter, etc.
// User should provide the key as a cli arg.
// Punctutations are not impacted by the key. Lower/upper case respected.
// If the key isn't 26 chars => Explain usage
int main(int argc, string argv[])
{
    // Must only has 2 cli arg (name program and key)
    if (argc == 2)
    {
        // We check for the key length
        if (strlen(argv[1]) == 26)
        {
            // VALIDATION PHASE
            // We check if key is only letters with a for loop to go through each letter of the key
            for (int i = 0, n = strlen(argv[1]); i < n; i++)
            {
                if (isalpha(argv[1][i]) == false)
                {
                    printf("Key must only be letters.");
                    return 1;
                }
                // We check for the key not to have same letters.
                // We'll compare the previous letter with the actual letter
                for (int j = i + 1, m = strlen(argv[1]); j < m; j++)
                {
                    if (tolower(argv[1][i]) == tolower(argv[1][j]))
                    {
                        printf("Key must not have same letters.\n");
                        return 1;
                    }
                }
            }
            string text = get_string("plaintext: ");
            printf("ciphertext: ");
            // Program
            for (int i = 0, n = strlen(text); i < n; i++)
            {
                // Lowercase letters must be encrypted into a new lowercase character 
                if (isalpha(text[i]) && islower(text[i]))
                {
                    printf("%c", tolower(argv[1][text[i] - 97]));
                }
                // Uppercase letters must be encrypted into a new uppercase character 
                else if (isalpha(text[i]) && isupper(text[i]))
                {
                    printf("%c", toupper(argv[1][text[i] - 65]));
                }
                // Maintain punctuations and numbers
                else
                {
                    printf("%c", text[i]);
                }
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Key must have 26 characters.\n");
            return 1;
        }

    }
    else
    {
        printf("Usage: substitution key\n");
        return 1;
    }
}