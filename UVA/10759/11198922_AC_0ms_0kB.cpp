// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[30][200];
ll n , x;

ll f(int i , int sum)
{
    if(i==n){

        if(sum>=x)return 1;
        return 0;
    }

    if(dp[i][sum]!=-1)return dp[i][sum];

    ll value = 0;

    for(int j=1;j<=6;j++){

        value+=f(i+1  ,sum+j);
    }

    return dp[i][sum] = value;
}

int main(void)
{
    while(scanf("%lld %lld", &n , &x)==2){

        if(!n&&!x)break;

        memset(dp , -1 , sizeof(dp));

        ll ans = f(0 , 0);

        ll dem = 1;

        for(int i=0;i<n;i++){

            dem*=6;

            ll gcd = __gcd(ans , dem);
            ans/=gcd;
            dem/=gcd;
        }

        if(ans==0)printf("0\n");
        else if(dem==1)printf("%lld\n",ans);
        else printf("%lld/%lld\n",ans , dem);
    }

    return 0;
}
