// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
ll fact[1000005];
void pre()
{
    fact[0] = 1;
    for(ll i=1;i<=1000000;i++){

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

ll NCR(ll n , ll r)
{
    ll t1 = fact[n];
    ll t2 = fact[n-r]*fact[r];
    t2%=MOD;

    t1 = t1*BM(t2 , MOD-2 , MOD);
    t1%=MOD;
    return t1;
}

int main(void)
{
    pre();
    ll h , w , n;
    scanf("%lld %lld %lld",&h , &w , &n);

    vector<pair<ll , ll > > v;

    for(int i=0;i<n;i++){

        ll in1 , in2;
        scanf("%lld %lld",&in1 , &in2);
        v.push_back({in1 , in2});
    }

    v.push_back({h , w});
    sort(v.begin() , v.end());

    ll ans[n+10];

    for(int i=0;i<=n;i++){

        ans[i] = NCR(v[i].first+v[i].second-2 , v[i].first-1);

        for(int j=0;j<i;j++){

            if(v[j].first<=v[i].first&&v[j].second<=v[i].second){

                ans[i]-=ans[j]*NCR(v[i].first-v[j].first + v[i].second-v[j].second , v[i].first-v[j].first);
                ans[i]%=MOD;
                ans[i]+=MOD;
                ans[i]%=MOD;
            }
        }
    }
    printf("%lld\n",ans[n]);

    return 0;
}
