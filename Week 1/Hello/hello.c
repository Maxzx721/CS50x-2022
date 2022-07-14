#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? ");     //gets user's name
    printf("hello, %s\n", name);        //output their name
}