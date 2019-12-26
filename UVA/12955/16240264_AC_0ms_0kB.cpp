// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v;

void pre()
{
    v.push_back(1);
    for(ll i=2;;i++){

        ll temp = i*v[i-2];
        if(temp>100000)break;
        v.push_back(temp);
    }
}

ll dp[100005];

ll f(ll n)
{
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];

    ll value = 1e9;

    for(int i=0;i<v.size();i++){

        if(v[i]<=n)value = min(value , f(n-v[i])+1);
    }
    return dp[n] = value;
}

int main(void)
{
    pre();
    ll n;
    memset(dp , -1 , sizeof(dp));

    while(scanf("%lld",&n)==1){

        printf("%lld\n",f(n));
    }

    return 0;
}
