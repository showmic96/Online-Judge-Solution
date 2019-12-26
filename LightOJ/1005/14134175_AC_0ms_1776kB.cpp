// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[105][105];

ll f(int i , int j)
{
    if(i==j)return 1;
    if(j==0)return 1;
    if(j==1)return i;

    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j] = f(i-1 , j) + f(i-1 , j-1);
}

ll fact(ll n)
{
    if(n==0)return 1;
    return n*fact(n-1);
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , k;
        scanf("%d %d",&n , &k);
        if(k>n)printf("Case %d: 0\n",++c);
        else printf("Case %d: %lld\n",++c , f(n , k)*f(n , k)*fact(k));
    }

    return 0;
}
