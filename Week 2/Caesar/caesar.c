#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool not_digits(string check)
{
    for (int i = 0; i < strlen(check); i++)
    {
        if (check[i] < 48 || check[i] > 57)     //check if it contains any letter or english signs & symbols
        {
            return true;
        }
    }
    return false;
}

int main(int argc, string argv[])
{
    while (argc != 2 || not_digits(argv[1]))        //check if user input 2 strings or not
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("plaintext:  ");
    int shift = atoi(argv[1]);

    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]))     //check if the letter is upper case or not
        {
            text[i] = 'A' + ((text[i] - 'A' + shift) % 26);
        }
        else if (islower(text[i]))       //check if the letter is lower case or not
        {

            text[i] = 'a' + ((text[i] - 'a' + shift) % 26);
        }
    }
    printf("ciphertext: %s\n", text);       //output the string after shifting the given amout of number

    return 0;
}