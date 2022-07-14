#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number;
    do
    {
        number = get_int("Height :");       //get user's input
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
        printf("  ");       //print space
        temp = 0;
        while (temp != i)
        {
            printf("#");        //print #
            temp++;
        }
        printf("\n");       //skip line
    }
}