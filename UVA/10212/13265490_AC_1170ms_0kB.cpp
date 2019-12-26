// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n , m;
    while(scanf("%lld %lld",&n, &m)==2){

        ll ans = 1;

        for(ll i=n;i>=n-m+1;i--){

            ans*=i;
            while(ans%10==0)ans/=10;
            ans%=10000000000LL;
        }

        printf("%lld\n",ans%10);
    }

    return 0;
}
