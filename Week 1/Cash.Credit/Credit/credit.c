#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int digits[16], temp = 0, i = 0, flag = 0;
    long number = get_long("Number: ");

    while (number != 0)
    {
        digits[i++] = number % 10;      //store every digits into array "digits"
        number /= 10;
    }

    i = 0;
    while (i != 8)
    {
        int digitTimesTwo = digits[i++ * 2 + 1] * 2;        //calculate every other digit
        if ((digitTimesTwo / 10) != 0)      //if the result have 2 digit, then I break it down
        {
            temp += digitTimesTwo / 10;
            temp += digitTimesTwo % 10;
        }
        else
        {
            temp += digitTimesTwo;      //simply add the result to "temp"
        }
    }

    i = 0;
    while (i != 8)
    {
        temp += digits[i++ * 2];        //add the digits that weren’t multiplied by 2
    }

    if (temp % 10 == 0)     //check if the last digit if 0 or not
    {
        if (digits[14] == 3 && (digits[13] == 4 || digits[13] == 7))        //check if it is AMEX
        {
            printf("AMEX\n");
        }
        else if (digits[15] == 5 && (digits[14] == 1 || digits[14] == 2 || digits[14] == 3 || digits[14] == 4
                                     || digits[14] == 5))        //check if it is MASTERCARD
        {
            printf("MASTERCARD\n");
        }
        else if (digits[15] == 4 || digits[12] == 4)        //check if it is VISA
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}