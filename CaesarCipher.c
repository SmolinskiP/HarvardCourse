#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
//check if the user put exactly 1 input
    {
        int text_l = strlen(argv[1]);
        for (int i = 0; i < text_l; i++)
//check all the input contains digits
        {
            if isdigit(argv[1][i]) //jesli kazdy kolejny znak jest cyfra, kontynuj
            {
                continue;
            }
            else
            {
                printf("Usage: ./caesar key\n"); // jak nie wywal blad
                return 1;
            }
        }
        if (argv[1] >= 0)
//check input is positive
        {
            string user_text = get_string("plaintext:"); //pobierz text od usera
            string code_text = ""; //utworz pusta zmienna (w przyszlosci bedzie tu zakodowany text)
            int user_text_l = strlen(user_text);

            for (int i = 0; i < user_text_l; i++)
            {
                if islower(user_text[i]) //jesli litera jest mala:
                {
                    user_text[i] -= 97; //cofnij o 97 czyli do 0
                    user_text[i] = user_text[i] + (atoi(argv[1])); //dodaj podany przez uzytkownika klucz
                    user_text[i] = user_text[i] % 26; //modulo 26(klucz byl 53 - a to 0, 0+53 to 53, podzielic z reszta na 26 wychodzi 1 czyli b)
                    user_text[i] += 97; //niestety b to 98 wiec 1 + 97 zeby otrzymac wynik

                    code_text += user_text[i]; //dodajemy kolejne litery do wyniku w petli
                }
                else if isupper(user_text[i]) //analogicznie, jak litera jest duza
                {
                    user_text[i] -= 65;
                    user_text[i] = user_text[i] + (atoi(argv[1]));
                    user_text[i] = user_text[i] % 26;
                    user_text[i] += 65;

                    code_text += user_text[i];
                }
            }
            printf("ciphertext:%s\n", user_text);
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

