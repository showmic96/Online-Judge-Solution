// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100000+5;

ll dp[MAX] , gdp[MAX] , hdp[MAX] , two[MAX+9];
ll MOD = 1e9 + 7;

ll f(int i);

vector<ll>v;

ll p(ll value , int l)
{
    return two[l];
}

ll g(int i)
{
    if(i==0)return v[0];

    if(gdp[i]!=-1)return gdp[i];

    return gdp[i] = (g(i-1)+f(i))%MOD;
}

ll h(int i)
{
    if(i==0)return v[0];

    if(hdp[i]!=-1)return hdp[i];

    return hdp[i] = (h(i-1)*v[i]+p(2, i-1)*v[i])%MOD;
}

ll f(int i)
{
    if(i==0)return v[0];

    if(dp[i]!=-1)return dp[i];

    return dp[i] = (g(i-1) + h(i))%MOD;
}

void pre(int n)
{
    for(int i=0;i<=n;i++){

        hdp[i] = -1;
        gdp[i] = -1;
        dp[i] = -1;
    }
}

int main(void)
{

    two[0] = 1;
    for(int i=1;i<MAX;i++){

        two[i] = two[i-1]*2;
        two[i]%=MOD;
    }

    int t;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);

        pre(n);

        v.clear();

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        printf("%lld\n",f(n-1));
    }

    return 0;
}
