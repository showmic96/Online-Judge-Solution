// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6+9;
const ll MOD = 1e9+7;

ll fact[3*MAX+9];

void pre()
{
    fact[0] = 1;
    for(ll i=1;i<=3*MAX;i++){

        fact[i] = fact[i-1]*i;
        fact[i]%=MOD;
    }
}

ll BM(ll a , ll b , ll mod)
{
    if(b==0)return 1;

    ll x = BM(a , b/2 , mod);
    x = (x*x)%mod;

    if(b%2==1)x = (x*a)%mod;

    return x;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    pre();

    while(t--){

        ll n , k;
        scanf("%lld %lld",&n , &k);

        ll d = (fact[n]*fact[k-1])%MOD;

        ll ans = (fact[n+k-1]%MOD)*(BM(d , MOD-2 , MOD));
        ans%=MOD;

        printf("Case %d: %lld\n", ++c , ans);
    }

    return 0;
}
