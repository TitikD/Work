#include <math.h>
# include <stdio.h>
# include <cs50.h>
int main(void)
{
    float num;
    int count = 0;
    printf("O hai!");
    do
    {
        printf("How much change is owed? ");
        num = GetFloat();
    }while(0>num);
    float roundf (float num);
    double numb = (double) num;
    double numbe =  numb * 100+0.1;
    int n = (int) numbe;
    while(n>=25)
    {
        n=n-25;
        count++;
    }
    while(n>=10)
    {
        n=n-10;
        count++;
    }
    while(n>=5)
    {
        n=n-5;
        count++;
    }
    while(n>=1)
    {
        n=n-1;
        count++;
    }
    printf("%d\n",count);
}