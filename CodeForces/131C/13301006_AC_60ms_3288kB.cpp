// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[35][35];

ll f(int i , int j)
{
    if(j==0)return 1;
    if(i==j)return 1;
    if(j==1)return i;

    if(dp[i][j]!=-1)return dp[i][j];

    return dp[i][j] = f(i-1 , j)+f(i-1 , j-1);
}

int main(void)
{
    int n , m , t;
    scanf("%d %d %d",&n , &m , &t);

    memset(dp , -1 , sizeof(dp));
    ll ans = 0;

    for(int i=4;i<=n;i++){

        for(int j=1;i+j<=t&&j<=m;j++){

            if(i+j==t){

               ans+=f(n , i)*f(m , j);
            }
        }
    }

    printf("%lld\n",ans);

    return 0;
}
