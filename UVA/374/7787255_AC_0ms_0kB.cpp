// In the name of Allah the most Merciful

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll BigMod(ll a , ll b , ll m)
{
    if(b==0)return 1%m;

    ll x = BigMod(a , b/2  , m);

    x = (x*x)%m;

    if(b%2==1)x=(x*a)%m;

    return x;
}


int main(void)
{
    ll a , b , m;

    while(cin >> a >> b >> m)cout << BigMod(a , b , m) << endl;

    return 0;
}
