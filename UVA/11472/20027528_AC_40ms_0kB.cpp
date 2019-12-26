// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 1000000007;
int Set(int n , int pos)
{
    return n|(1<<pos);
}
bool Check(int n , int pos)
{
    return n&(1<<pos);
}
ll dp[105][11][(1<<10)+10];
int n , m;

ll f(int i , int last , int mask)
{
    if(i==m){
        if(mask==(1<<n)-1)return 1;
        return 0;
    }
    if(dp[i][last][mask]!=-1)return dp[i][last][mask];
    ll value = 0;
    if(mask==0){
        value+=f(i+1, 0 , mask);
        for(int j=1;j<n;j++){
            value+=f(i+1, j , Set(mask , j));
        }
    }
    else{
        if(last-1>=0){
            value+=f(i+1, last-1, Set(mask , last-1));
        }
        if(last+1<n){
            value+=f(i+1, last+1, Set(mask , last+1));
        }
    }
    return dp[i][last][mask] = value%MOD;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n , &m);
        memset(dp , -1 , sizeof(dp));
        printf("%lld\n",f(0 , 0 , 0));
    }
    return 0;
}
