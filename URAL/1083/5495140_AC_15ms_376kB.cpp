#include<iostream>
#include<string.h>
#include<string>
int recursion(int a,int b);
using namespace std;

int main(void)
{
    int a , b , c , d; char x[25];
    cin >> a >> x;
    b=strlen(x);
    d=recursion(a ,b);
    cout << d << endl;
            return 0;
}

int recursion(int a,int b)
{
    if (a>0) return a* recursion(a-b,b);
    else return 1;
}
