// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[1005][1005];

ll ar[1005];

ll MOD = 1e9 + 7;

ll f(int i , int j)
{
    if(i==j){

        return dp[i][j] = 1;
    }

    if(dp[i][j]!=-1)return dp[i][j];

    return dp[i][j] = (f(i , j-1) + f(ar[j-1] , j-1) + 1)%MOD;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){

        scanf("%d",&ar[i]);
    }

    printf("%lld\n", f(1 , n+1) - 1LL);

    return 0;
}
