// In the name of Allah the lord of the worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll a);

ll g(ll a)
{
    if(a<0)return 0;
    if(a==0)return 1;

    return f(a-1) + g(a-2);
}

ll f(ll a)
{
    if(a<0)return 0;
    if(a==0)return 1;

    return f(a-2) + 2*g(a-1);
}

int main(void)
{
    ll a;

    while(cin >> a){

        if(a==-1)break;

        if(a%2==1){cout << 0 << endl;continue;}
        cout << f(a) << endl;
    }

    return 0;
}
