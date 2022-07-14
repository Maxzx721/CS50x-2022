#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number;
    do
    {
        number = get_int("Height: ");       //gets user input
    }
    while (number < 1 || number > 8);

    for (int i = 1; i <= number; i++)
    {
        int temp = number - i;
        while (temp)
        {
            printf(" ");        //print space
            temp--;
        }
        temp = i;
        while (temp)
        {
            printf("#");        //print #
            temp--;
        }
        printf("\n");       //skip to new line
    }
}