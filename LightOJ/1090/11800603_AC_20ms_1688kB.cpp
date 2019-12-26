// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int five(ll x)
{
    int ans = 0;

    for(ll i=5;i<=x;i*=5){

        ans+=(x/i);
    }

    return ans;
}

int two(ll x)
{
    int ans = 0;

    for(ll i=2;i<=x;i*=2){

        ans+=(x/i);
    }

    return ans;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll n , r , p , q;
        scanf("%lld %lld %lld %lld",&n , &r , &p , &q);

        ll f = five(n)-five(n-r)-five(r);
        ll t = two(n)-two(n-r)-two(r);

        ll temp = p;

        ll counter = 0;

        while(p%5==0){

            counter++;
            p/=5;
        }

        f+=counter*q;

        counter = 0;

        while(p%2==0){

            counter++;
            p/=2;
        }

        t+=counter*q;

        printf("Case %d: %lld\n",++c , min(t , f));
    }
    return 0;
}
