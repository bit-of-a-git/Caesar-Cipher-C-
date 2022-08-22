#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int letters = 0;

int main(int argc, string argv[])
{
    // Checks whether there are two arguments, rejects more or less
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // If there are 2 arguments, checks whether they are all numbers. Prints them if yes, cancels if no
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if ((argv[1][i] < 48) || (argv[1][i] > 57))
            {
                letters++, i++;
            }
        }
        // If 1 letter or more in the key, gives an error message
        if (letters > 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            // Turns the key from a string to an integer
            int k = atoi(argv[1]);
            // As this uses the alphabet only, values above 26 are not necessary. Reduces k to within the range of 0 and 26
            while (k >= 26)
            {
                k -= 26;
            }
            // Gets plaintext from the user to encrypt
            string plaintext = get_string("Plaintext: ");
            // Prints "Ciphertext" before encrypting plaintext
            printf("ciphertext: ");
            for (int i = 0, n = strlen(plaintext); i < n; i++)
            {
                if (isupper(plaintext[i]))
                {
                    plaintext[i] += k;
                    if (plaintext[i] > 90)
                    {
                        plaintext[i] -= 26;
                    }
                    printf("%c", (plaintext[i]));
                }
                // As lower integers are close to the limit of ASCII, this turns them into integers,
                // makes sure they're in the range of lowercase characters, and prints them out.
                else if (islower(plaintext[i]))
                {
                    int lower = plaintext[i];
                    lower += k;
                    if (lower > 122)
                    {
                        lower -= 26;
                    }
                    printf("%c", lower);
                }
                // Lets any other characters pass through unaltered
                else
                {
                    printf("%c", (plaintext[i]));
                }
            }
        }
    }
    printf("\n");
}
