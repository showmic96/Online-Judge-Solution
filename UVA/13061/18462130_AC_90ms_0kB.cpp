// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 9999959999;
ll dp[1005][3005];

ll f(int n , int m)
{
    //if(n==0&&m==0)return 1;
    if(dp[n][m]!=-1)return dp[n][m];
    ll value = 1;

    if(n>0)value+=f(n-1 , m+1);
    if(m>0)value+=f(n , m-1);

    return dp[n][m] = value%MOD;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));
    int n , m;
    while(scanf("%d %d",&n , &m)==2){
        if(n==0&&m==0)break;
        printf("%lld\n",f(n , m));
    }
    return 0;
}
