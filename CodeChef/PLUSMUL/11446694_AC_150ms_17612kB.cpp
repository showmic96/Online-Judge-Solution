// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100000+5;

ll dp[MAX] , gdp[MAX] , hdp[MAX];
ll MOD = 1e9 + 7;

ll f(int i);

vector<ll>v;

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);

        v.clear();

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            v.push_back(in);
        }

        dp[0] = gdp[0] = hdp[0] = v[0];

        ll p = 1;

        for(int i=1;i<n;i++){

            hdp[i] = (hdp[i-1]*v[i]+p*v[i])%MOD;
            dp[i] = (gdp[i-1] + hdp[i])%MOD;
            gdp[i] = (gdp[i-1]+dp[i])%MOD;

            p*=2;
            p%=MOD;
        }

        printf("%lld\n",dp[n-1]);
    }

    return 0;
}
