#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * count_words - a helper function to count words in a string
 * @str: string to count its words
 * Return: Number of words, else 0
 */
int count_words(char *str)
{
    int count = 0;
    int in_word = 0;
    int i;
    if (str == NULL || *str == '\0')
        return (0);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            if (!in_word)
            {
                in_word = 1;
                count++;
            }
        }
        else
        {
            in_word = 0;
        }
    }
    return (count);
}
/**
 * allocate_words - allocate memory for words array
 * @num_words: number of words
 * Return: Pointer to allocated memory, else NULL
 */
char **allocate_words(int num_words)
{
    char **words;
    words = (char **)malloc((num_words + 1) * sizeof(char *));
    if (words == NULL)
    {
        return (NULL);
    }
    return (words);
}
/**
 * split_words - split the string into words and store them in words array
 * @str: string to split
 * @words: array to store the words
 * Return: void
 */
void split_words(char *str, char **words)
{
    int word_index = 0;
    int word_start = 0;
    int in_word = 0;
    int i, j;
    int word_length;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            if (!in_word)
            {
                in_word = 1;
                word_start = i;
            }
        }
        else
        {
            if (in_word)
            {
                word_length = i - word_start;
                words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
                if (words[word_index] == NULL)
                {
                    for (j = 0; j < word_index; j++)
                    {
                        free(words[j]);
                    }
                    free(words);
                    return;
                }
                strncpy(words[word_index], str + word_start, word_length);
                words[word_index][word_length] = '\0';
                word_index++;
                in_word = 0;
            }
        }
    }
    if (in_word)
    {
        word_length = strlen(str + word_start);
        words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
        if (words[word_index] == NULL)
        {
            for (j = 0; j < word_index; j++)
            {
                free(words[j]);
            }
            free(words);
            return;
        }
        strcpy(words[word_index], str + word_start);
        word_index++;
    }
    words[word_index] = NULL;
}
/**
 * strtow - a function to split a string of words and print each word
 * @str: A string of words
 * Return: Pointers to words that are split from the given string
 */
char **strtow(char *str)
{
    int num_words;
    char **words;
    if (str == NULL || *str == '\0')
    {
        return (NULL);
    }
    num_words = count_words(str);
    if (num_words == 0)
    {
        return (NULL);
    }
    words = allocate_words(num_words);
    if (words == NULL)
    {
        return (NULL);
    }
    split_words(str, words);
    return (words);
}

