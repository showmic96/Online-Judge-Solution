// C++ Program to convert decimal number to
// roman numerals
#include <bits/stdc++.h>
using namespace std;

// To add corresponding base symbols in the array
// to handle cases which follow subtractive notation.
// Base symbols are added index 'i'.
int sub_digit(char num1, char num2, int i, char *c)
{
    c[i++] = num1;
    c[i++] = num2;
    return i;
}

// To add symbol 'ch' n times after index i in c[]
int digit(char ch, int n, int i, char *c)
{
    for (int j = 0; j < n; j++)
        c[i++] = ch;
    return i;
}

string printRoman(int number)
{
    char c[10001];
    int i = 0;

    while (number != 0)
    {
        if (number >= 1000)
        {
            i = digit('M', number/1000, i, c);
            number = number%1000;
        }
        else if (number >= 500)
        {
            if (number < 900)
            {
               i = digit('D', number/500, i, c);
               number = number%500;
            }
            else
            {
                i = sub_digit('C', 'M', i, c);
                number = number%100 ;
            }
        }

        else if (number >= 100)
        {

            if (number < 400)
            {
                i = digit('C', number/100, i, c);
                number = number%100;
            }

            else
            {
                i = sub_digit('C','D',i,c);
                number = number%100;
            }
        }

        else if (number >= 50 )
        {

            if (number < 90)
            {
                i = digit('L', number/50,i,c);
                number = number%50;
            }
            else
            {
                i = sub_digit('X','C',i,c);
                number = number%10;
            }
        }

        else if (number >= 10)
        {
            if (number < 40)
            {
                i = digit('X', number/10,i,c);
                number = number%10;
            }

            else
            {
                i = sub_digit('X','L',i,c);
                number = number%10;
            }
        }
        else if (number >= 5)
        {
            if (number < 9)
            {
                i = digit('V', number/5,i,c);
                number = number%5;
            }
            else
            {
                i = sub_digit('I','X',i,c);
                number = 0;
            }
        }
        else if (number >= 1)
        {
            if (number < 4)
            {
                i = digit('I', number,i,c);
                number = 0;
            }
            else
            {
                i = sub_digit('I', 'V', i, c);
                number = 0;
            }
        }
    }
    string temp = "";

    for (int j = 0; j < i; j++)
        temp+=c[j];

    return temp;
}

int main()
{
    int n;
    while(scanf("%d",&n)==1){

        if(!n)break;
        int i = 0 , v = 0 , x = 0 , l = 0 , c = 0;

        for(int i1=1;i1<=n;i1++){

            string temp = printRoman(i1);
            int si = temp.size();

            for(int j=0;j<si;j++){

                if(temp[j]=='I')i++;
                else if(temp[j]=='V')v++;
                else if(temp[j]=='X')x++;
                else if(temp[j]=='L')l++;
                else c++;
            }
        }

        printf("%d: %d i, %d v, %d x, %d l, %d c\n",n , i , v , x , l , c);
    }
    return 0;
}
