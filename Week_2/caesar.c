// Implement a program that encrypts messages using Caesar's cipher.

// User should provide a cli argument for the key. Check if not a number!

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool isDigit(string text);
string encryption(string plaintext);


int main(int argc, string argv[])
{
    // Check for cli args: 0 = name program, 1 = key
    if (argc == 2)
    {
        // Check if arg cli is indeed a digit
        if (isDigit(argv[1]) == true)
        {
            // Convert argv[1] into an integer
            int key = atoi(argv[1]);
            string plaintext = get_string("plaintext: ");
            
            printf("ciphertext: ");
            // Create a for loop to go through each character of 'plaintext' and add 'keyEncryption' position to the letter
            for (int i = 0, n = strlen(plaintext); i < n; i++)
            {
                char letter_encrypted;
                // Distinction between uppercase, lowercase and punctuation.
                if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
                {
                    letter_encrypted = ((plaintext[i] - 'A' + key) % 26) + 'A';
                    printf("%c", letter_encrypted);
                }
                else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
                {
                    letter_encrypted = ((plaintext[i] - 'a' + key) % 26) + 'a';
                    printf("%c", letter_encrypted);
                }
                else 
                {
                    printf("%c", plaintext[i]);
                }
            }
            printf("\n");
            return 0;
        }
        // If arg isn't digit
        else 
        {
            printf("Usage: caesar key\n");
            return 1;
        }
    }
    // If arg is != 2
    else
    {
        printf("Usage: caesar key\n");
        return 1;
    }
}

bool isDigit(string text)
{
    bool result;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isdigit(text[i]))
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    return result;

}
