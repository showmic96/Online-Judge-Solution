// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fact(ll x)
{
    if(x==0)return 1;
    return x*fact(x-1);
}

ll dp[15];
ll d(ll x)
{
    if(x==1)return 0;
    if(x==2)return 1;

    if(dp[x]!=-1)return dp[x];
    return dp[x] = (x-1)*(d(x-1)+d(x-2));
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));
    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        printf("%lld/%lld\n",d(n),fact(n));
    }

    return 0;
}
