// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , m , k , dp[1005][105][3] , p[1005];

ll f(int i , int tot , int taken)
{
    if(i==0){
        if(tot==0)return 1;
        return 0;
    }
    if(dp[i][tot][taken]!=-1)return dp[i][tot][taken];
    ll value = 0;

    for(int j=0;j<=9;j++){
        if(i==1&&j==0)continue;
        ll temp = tot+p[i]*j;

        if(taken==0&&temp%k==0&&j>0){
            value += f(i-1 , temp%k , 1);
        }
        else if(taken==0){
            value += f(i-1 , temp%k , 0);
        }
        else{
            value += f(i-1 , tot , taken);
        }
    }
    return dp[i][tot][taken] = value%m;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));
    scanf("%lld %lld %lld",&n , &k , &m);
    p[n] = 1%k;
    for(int i=n-1;i>=1;i--)p[i] = (p[i+1]*10LL)%k;
    printf("%lld\n",f(n , 0 , 0));

    return 0;
}
