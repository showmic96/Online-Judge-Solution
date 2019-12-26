// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[3005][3005];

ll f(int i , int j)
{
    if(j==0)return 1;
    if(j==1)return i;
    if(i==j)return 1;

    if(dp[i][j]!=-1)return dp[i][j];

    ll value = f(i-1 , j-1)+f(i-1 , j);
    return dp[i][j] = value;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));
    ll n , k;
    while(scanf("%lld %lld",&n , &k)==2){

        if(!n&&!k)break;

        if(n-k<k)k = n-k;

        if(k==2)printf("%lld\n",(ll)((double)n*(n-1)/2.00));
        else printf("%lld\n",f(n , k));
    }
    return 0;
}
