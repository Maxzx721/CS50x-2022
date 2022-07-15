#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    float W = 0, S = 0, index = 0, length = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')     //check if that is a spcae
        {
            W++;
            continue;
        }
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')     //check if that is a "." or "!" or "?"
        {
            S++;
            continue;
        }
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))      //check if that is a alphabet
        {
            length++;
        }
    }
    W++;

    index = 0.0588 * (length / W * 100) - 0.296 * (S / W * 100) - 15.8;     //calculate the score
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) round(index));
    }
}