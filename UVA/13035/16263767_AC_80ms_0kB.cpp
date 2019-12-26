// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1e9+7;

ll BM(ll a, ll b , ll M)
{
    if(b==0)return 1%M;
    ll x = BM(a , b/2 , M);
    x = (x*x)%M;

    if(b%2==1)x = (x*a)%M;
    return x;
}

int main(void)
{
    int t , c = 0;

    scanf("%d",&t);
    while(t--){

        ll n;
        scanf("%lld",&n);
        ll ans = n*(n+1LL);

        ans%=MOD;
        ans = ans*(n+2LL);
        ans%=MOD;

        ans*=BM(3 , MOD-2 , MOD);
        ans%=MOD;

        printf("Case %d: %d\n",++c , ans);
    }

    return 0;
}
