#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ncr[1005][1005] , MOD = 10056 , dp[1005];

ll NcR(ll n , ll c)
{
    if(n==c)return 1;
    if(c==1)return n;

    if(ncr[n][c]!=-1)return ncr[n][c];

    return ncr[n][c] = (NcR(n-1 , c-1) + NcR(n-1 , c))%MOD;
}

ll f(int n)
{
    if(n<=1)return 1;
    if(dp[n]!=-1)return dp[n];

    ll value = 0;
    for(int i=n;i>=1;i--){

        value+=NcR(n , i)*f(n-i);
        value%=MOD;
    }
    return dp[n] = value;
}

int main(void)
{
    memset(ncr , -1 , sizeof(ncr));
    memset(dp , -1 , sizeof(dp));

    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        printf("Case %d: %lld\n",++c , f(n));
    }
    return 0;
}