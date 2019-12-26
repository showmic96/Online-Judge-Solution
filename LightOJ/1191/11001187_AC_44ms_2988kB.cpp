// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[55][55][55];

int n , k , m;

ll f(int i , int j , int pre)
{
    if(i<=0){

        if(j==0)return 1;
        return 0;
    }

    if(dp[i][j][pre]!=-1)return dp[i][j][pre];

    ll value = 0;

    for(int i1=1;i1<=m;i1++){

        if(i-i1>=0){

            value+=f(i-i1 , j-1 , pre);
        }

        else break;
    }

    return dp[i][j][pre] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    memset(dp , -1 , sizeof(dp));

    while(t--){

        scanf("%d %d %d", &n , &k , &m);

        printf("Case %d: %lld\n",++c , f(n , k , m));
    }
    return 0;
}
