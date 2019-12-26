// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll x , ll n)
{
    if(x%2)return (x+1)/2;
    return f(x+(n-x/2) , n);
}

int main(void)
{
    ll n , q;
    scanf("%lld %lld",&n , &q);
    while(q--){

        ll in;
        scanf("%lld",&in);

        printf("%lld\n",f(in , n));
    }
    return 0;
}
