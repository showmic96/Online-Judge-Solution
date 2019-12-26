#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>

using namespace std;

int main(void)
{   long long a , b , c;
    cin >> a;
    if(a%5==0) cout << a/5 << endl;
    else cout << (a/5)+1 << endl;

    return 0;
}
