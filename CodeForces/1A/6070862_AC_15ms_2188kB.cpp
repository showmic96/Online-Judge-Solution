#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    long long int a , b , c;
    cin >> a >> b >> c;
    if(a%c!=0)a=(a-(a%c))+c;
    if(b%c!=0)b=(b-(b%c))+c;
    cout << (a*b)/(c*c) << endl;
    return 0;
}
