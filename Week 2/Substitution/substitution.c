#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool every_letter(string check)
{
    if (strlen(check) != 26)            //check if the length of string is 26 or not
    {
        return true;
    }

    int temp[26];
    for (int i = 0; i < 26; i++)
    {
        if (temp[toupper(check[i]) - 65] == 1 || !isalpha(check[i]))            //check if the letter is repeated or not
        {
            return true;
        }
        else
        {
            temp[toupper(check[i]) - 65] = 1;           //put 1 in the corresponding arrry to mark the letter does appear
        }
    }

    return false;
}

int main(int argc, string argv[])
{
    if (argc == 2 && every_letter(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string text = get_string("plaintext:  ");

    for (int i = 0; i < strlen(text); i++)
    {
        if (ispunct(text[i]))
        {
            continue;
        }
        else if (isupper(text[i]))
        {
            text[i] = toupper(argv[1][text[i] - 65]);           //shift the letter
        }
        else if (islower(text[i]))
        {
            text[i] = tolower(argv[1][text[i] - 97]);           //shift the letter
        }
    }

    printf("ciphertext: %s\n", text);           //output the result
    return 0;
}