// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[110];

ll f(int i)
{
    if(i==0)return 1;
    if(i<0)return 0;

    if(dp[i]!=-1)return dp[i];

    ll value = 0;

    value+= 4*f(i-2);
    value+= 2*f(i-3);
    value+= f(i-1);

    return dp[i] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);

    memset(dp , -1 , sizeof(dp));

    while(t--){

        int n;
        scanf("%d",&n);

        printf("%lld\n",f(n));
    }

    return 0;
}
