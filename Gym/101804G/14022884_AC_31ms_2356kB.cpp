// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1e9+7;
ll fact[300005];

void f()
{
    fact[0] = 1;
    for(ll i=1;i<300005;i++){

        fact[i] = fact[i-1]*i;
        fact[i]%=MOD;
    }
}

ll BA(ll a , ll b , ll MOD)
{
    if(b==1)return a%MOD;

    ll x = BA(a , b/2 , MOD);
    x = (x+x)%MOD;
    if(b%2==1)x = (x+a)%MOD;

    return x;
}

ll BM(ll a, ll b , ll M)
{
    if(b==0)return 1%M;

    ll x = BM(a , b/2 , M);
    x = BA(x , x , M)%M;

    if(b%2==1)x = BA(x , a , M)%M;
    return x;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    f();

    ll n , c;
    cin >> n >> c;

    ll ans = 1;

    for(int i=0;i<n;i++){

        ans*=6;
        ans%=MOD;
    }

    ans*=fact[n];
    ans%=MOD;

    ll rem = c-3*n;
    ans*=fact[n+rem];
    ll d = fact[rem]*fact[n];
    d%=MOD;
    ans%=MOD;
    ans*=BM(d , MOD-2 , MOD);

    ans%=MOD;

    cout << (ans+MOD)%MOD << endl;

    return 0;
}
