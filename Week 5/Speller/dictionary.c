// Implements a dictionary's functionality

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 186019;

// A globle variable to keep track of the number of words inside of the dictionary
int numberOfWords = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    node *temp = table[hash(word)];

    while (temp != NULL)
    {
        if (!strcasecmp(temp->word, word))
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int total = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }

    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    char dictWord[LENGTH + 1];
    while (fscanf(file, "%s", dictWord) != EOF)
    {
        node *newWord = malloc(sizeof(node));
        if (newWord == NULL)
        {
            return false;
        }
        strcpy(newWord->word, dictWord);
        newWord->next = table[hash(newWord->word)];
        table[hash(newWord->word)] = newWord;
        numberOfWords++;
    }
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return numberOfWords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *temp, *cursor;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            temp = cursor;
            cursor = temp->next;
            free(temp);
        }
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
