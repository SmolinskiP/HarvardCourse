#include <cs50.h>
#include <stdio.h> //standard things to do

int main(void) //main function of the program
{
    int n;
    do
    {
        n = get_int("Size of pyramid: \n"); //take input from the user
    }
    while (n < 1 || n > 8); //make sure the input is correct
    int x = n; //we need new variable called x
    for (int i = 0; i < n; i++)
    {
        printf("%.*s", x - 1, "                                            ");
        //first print desired amount of spaces
        printf("%.*s", i + 1, "############################################");
        //then we need desired amount of increasing automatically
        printf("  ");
        //then two spaces
        printf("%.*s", i + 1, "############################################");
        //then again desired amount of #
        printf("\n"); //and finally a newline
        x--;  //we need also decrease amount of spaces
    }
}
