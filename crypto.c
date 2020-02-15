#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int text_l = strlen(argv[1]);
        if (text_l != 26) //check the input is lenght 26
        {
            printf("Key must contain 26 characters.");
            return 1;
        }
        for (int i = 0; i < text_l; i++)
        {
            if isalpha(argv[1][i]) //jesli kazdy kolejny znak jest litera, kontynuj
            {
                continue;
            }
            else
            {
                printf("Usage: ./substitution key\n"); // jak nie wywal blad
                return 1;
            }
        }
        for (int i = 0; i < text_l; i++)
        {
            for (int j = i + 1; j < text_l;)
            {
                //printf("%c", tolower(argv[1][i]));
                //printf("%c\n", tolower(argv[1][j]));
                if (tolower(argv[1][i]) == tolower(argv[1][j]))
                {
                    printf("Usage: ./substitution key\n");
                    return 1;  //jesli sie powtarzaja wywal blad
                }
                else if (tolower(argv[1][text_l - 1]) == tolower(argv[1][text_l - 2]))
                {
                    printf("Usage: ./substitution key\n");
                    return 1; //w sumie chyba niepotrzebne
                }
                else
                {
                    //printf("%c%c\n", tolower(argv[1][i]), tolower(argv[1][j]));
                    j++; //jak przejdzie to zwieksz j i kontynuj sprawdzanie
                    continue;
                }
            }

        }
        string user_text = get_string("plaintext:");
        char coded_text[100] = "";
        int user_text_l = strlen(user_text);
        string inputed = argv[1];
        //printf("%s", inputed);
        for (int i = 0; i < user_text_l; i++)
        {
            if isalpha(user_text[i]) //jesli jest litera kontynuj
            {
                int position = (int)tolower(user_text[i]) - 97;
                if isupper(user_text[i]) //jak duza
                {
                    char x = toupper(inputed[position]);
                    strncat(coded_text, &x, 1); // to drukuj duza
                }
                else if islower(user_text[i]) //analogicznie
                {
                    char x = tolower(inputed[position]);
                    strncat(coded_text, (&x), 1);
                }
            }
            else
            {
                strncat(coded_text, &user_text[i], 1); //jak nie jest litera np spacja to przepisz po prostu
            }
        }
        printf("ciphertext:%s\n", coded_text); //drukuj wynik
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}
