// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e7+9;
const ll MOD = 1e9+7;
ll dp[MAX+9];

ll f(int n)
{
    if(n==1)return 0LL;
    if(n==2)return 1LL;
    if(dp[n]!=-1)return dp[n];
    return dp[n] = (((ll)n-1LL)*(f(n-1)+f(n-2))%MOD)%MOD;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        printf("%lld\n",f(n));
    }

    return 0;
}
