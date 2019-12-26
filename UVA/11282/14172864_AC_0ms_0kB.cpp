// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , k;

ll dp[25][25];
ll de[25];

ll d(int n)
{
    if(de[n]!=-1)return de[n];
    if(n==0)return 1;
    if(n==1)return 0;
    if(n==2)return 1;

    return de[n] = (ll)(n-1)*(d(n-1)+d(n-2));
}

ll f(int i , int j)
{
    if(i==n){

        if(j>k)return 0;
        return d(n-j);
    }

    if(dp[i][j]!=-1)return dp[i][j];

    return dp[i][j] = f(i+1 , j) + f(i+1 , j+1);
}

int main(void)
{
    while(scanf("%d %d",&n , &k)==2){

        memset(dp , -1 , sizeof(dp));
        memset(de , -1 , sizeof(de));

        printf("%lld\n",f(0 , 0));
    }
    return 0;
}
