
#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    long cN = get_long("Enter card number:\n");
    long n = cN; // we cant operate on our card number so new variable
    int count = 2;
    while (n > 100)
    {
        n = n / 10; // dividing by 10 until 100 is greater than number
        count ++;   // increasint count every time to get lenght of card number
        //printf("%li\n", n);   //I'M NOT IMPORTANT
    }
    
    long n2 = cN;
    int sum = 0;

    for (int i = 1; i <= count; i++)
    {
        int digit = n2 % 10;   // taking last cipher
        //printf("digit %i\n", digit);  //I'M NOT IMPORTANT
        if (i % 2 == 0) // if i is even we take the cipher * 2
        {
            if (digit * 2 > 9)
            {
                //because 12 need to be  1+2=3 or 12-9 also = 3
                sum += (digit * 2) - 9;
                //printf("sum%i\n", sum);   //I'M NOT IMPORTANT
            }
            else
            {
                //not greater than 9 so normal *2
                sum += digit * 2;
                //printf("sum%i\n", sum);   //I'M NOT IMPORTANT
            }
        }
        else
        {
            // digit is odd so we dont do *2
            sum += digit;
            //printf("sum%i\n", sum);   //I'M NOT IMPORTANT
        }
        n2 = n2 / 10;  //finally we need to decrase card number
        //printf("n2%li\n", n2);    //I'M NOT IMPORTANT
    }
    if (count == 15 && (n == 34 || n == 37) && (sum % 10 == 0))
    {
        //here some boolean checking type of card
        printf("AMEX\n");
    }
    else if (count == 16 && (n > 50 && n < 56) && (sum % 10 == 0))
    {
        printf("MASTERCARD\n");
    }
    else if ((count == 13 || count == 16) && (n / 10 == 4) && (sum % 10 == 0))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}


