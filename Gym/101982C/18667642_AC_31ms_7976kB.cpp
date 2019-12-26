// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1005;
ll ar[MAX] , dp[MAX][MAX] , MOD = 998244353;

ll f(int i , int rem)
{
    if(i==1002){
        if(rem==0)return 1;
        return 0;
    }
    if(dp[i][rem]!=-1)return dp[i][rem];
    ll value = f(i+1 , rem);
    if(rem>0&&ar[i]>0){
        value+=f(i+1 , rem-1)*ar[i];
    }
    return dp[i][rem] = value%MOD;
}

int main(void)
{
    int n , k;
    scanf("%d %d",&n , &k);
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        ar[in]++;
    }
    memset(dp , -1 , sizeof(dp));
    printf("%lld\n",f(0 , k));
    return 0;
}
