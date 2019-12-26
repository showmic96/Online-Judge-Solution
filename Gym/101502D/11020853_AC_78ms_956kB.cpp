#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[10005][7];
ll n;

ll f(int sum , int pre)
{
    if(sum>n)return 1e9;
    if(sum==n)return 0;

    if(dp[sum][pre]!=-1)return dp[sum][pre];

    ll value = 1e9;

    if(pre==1||pre==6){

        value = min(value , f(sum+2 , 2)+1);
        value = min(value , f(sum+3 , 3)+1);
        value = min(value , f(sum+4 , 4)+1);
        value = min(value , f(sum+5 , 5)+1);
    }

    if(pre==2||pre==5){

        value = min(value , f(sum+1 , 1)+1);
        value = min(value , f(sum+3 , 3)+1);
        value = min(value , f(sum+4 , 4)+1);
        value = min(value , f(sum+6 , 6)+1);
    }

    if(pre==3||pre==4){

        value = min(value , f(sum+2 , 2)+1);
        value = min(value , f(sum+1 , 1)+1);
        value = min(value , f(sum+6 , 6)+1);
        value = min(value , f(sum+5 , 5)+1);
    }

    return dp[sum][pre] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--){
        memset(dp , -1 , sizeof(dp));

        scanf("%lld",&n);
        ll ans = f(0 , 1);

        if(ans>100000)ans = -1;

        printf("%lld\n",ans);
    }
    return 0;
}
