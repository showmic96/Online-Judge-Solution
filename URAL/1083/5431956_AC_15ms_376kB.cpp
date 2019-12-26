#include<iostream>
#include<string.h>
using namespace std;
int factorial (int n, int x);
int main(void)
{
    char e[30];
    int a , b , c ,d;
    cin >> a >> e ;
    b=strlen(e);
    c=factorial(a , b);
    cout << c << endl;
    return 0;


}
int factorial(int n , int x)

{

    if (n>0) return n*factorial(n-x,x);
    else return 1;
}