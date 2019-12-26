// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1e9+7;

ll fact[1000005];

void pre()
{
    fact[0] = 1;
    for(ll i=1;i<1000005;i++){

        fact[i] = fact[i-1]*i;
        fact[i]%=MOD;
    }
}

ll BM(ll a , ll b , ll M)
{
    if(b==0)return 1%M;
    ll x = BM(a , b/2 , M);
    x = (x*x)%M;

    if(b%2==1)x = (x*a)%M;
    return x;
}

int main(void)
{
    pre();
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        vector<ll>v;

        scanf("%d",&n);

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        ll cur = 0 , ans = 1;

        for(int i=0;i<n;i++){

            ll temp = cur+v[i]-1;

            ans*=fact[temp];
            ans%=MOD;

            ans*=BM(fact[v[i]-1] , MOD-2 , MOD);
            ans%=MOD;

            ans*=BM(fact[cur] , MOD-2 , MOD);
            ans%=MOD;

            cur+=v[i];
        }

        printf("Case %d: %lld\n",++c , ans);
    }
    return 0;
}
