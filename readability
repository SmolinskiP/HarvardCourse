#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Enter your text:\n");
    int text_l = strlen(text);
    //printf("textlen = %i\n", text_l);
    int count_l = 0;
    int count_w = 1;
    int count_s = 0;
    for (int i = 0; i < text_l; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            count_l++;
        }
        else if (text[i] == ' ')
        {
            count_w++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_s++;
        }
    }
    float let_per_word = ((float)count_l / (float)count_w) * 100;
    float sen_per_word = ((float)count_s / (float)count_w) * 100;

    float index = (0.0588 * let_per_word) - (0.296 * sen_per_word) - 15.8;

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
        index = round(index);
        printf("Grade %i\n", (int)index);
    }

    //printf("litery: %i\n", count_l);
    //printf("słowa: %i\n", count_w);
    //printf("zdania: %i\n", count_s);
    //printf("liter na 100 slow: %f\n", let_per_word);
    //printf("zdan na 100 slow: %f\n", sen_per_word);
    //printf("index to: %f\n", index);
}

