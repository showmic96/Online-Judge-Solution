// In the name of Allah the most Merciful

#include<bits/stdc++.h>
using namespace std;

typedef long long lli;

/**************************************/
lli modpow(lli b, lli e, lli m)
{
    lli res=1;
    while (e>0)
    {
        if(e%2==1)res=(res*b)%m;
        e >>= 1; b=(b*b)%m;
    }
    return res;
}
/***************************************/

int main(void)
{
    lli a , b , m;
    while(cin >> a >> b >> m)cout << modpow(a , b , m) << endl;

    return 0;
}
