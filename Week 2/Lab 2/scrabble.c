#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");     //player1 win if score1 > socre2
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");     //player2 win if score2 > socre1
    }
    else
    {
        printf("Tie!\n");       //tie if both score are the same
    }
}

int compute_score(string word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)      //loop through each letter
    {
        if ((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122))      //check if it is A-Z || a-z or not
        {
            if (isupper(word[i]))
            {
                score += POINTS[word[i] - 65];      //assign score if it is A-Z
            }
            else
            {
                score += POINTS[word[i] - 97];      //assign score if it is a-z
            }
        }
    }
    return score;       //return score
}
