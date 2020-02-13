#include <cs50.h>
#include <stdio.h> //standard things to do
#include <math.h>

int main(void) //main function of the program
{
    float money = 0;
    do
    {
        money = round(100 * get_float("How much money?"));
        int count = 0;
        while (money > 25)
        {
            money -= 25;
            count++;
        }
        while (money > 10)
        {
            money -= 10;
            count ++;
        }
        while (money > 5)
        {
            money -= 5;
            count++;
        }
        while (money > 0)
        {
            money -= 1;
            count++;
        }
        printf("%i\n", count);
    }
    while (money < 0);
    
}
