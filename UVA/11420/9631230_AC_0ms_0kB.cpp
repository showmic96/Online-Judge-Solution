// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , s;

ll dp[67][67][2];

ll f(ll i , ll j , ll p)
{
    if(i==0){

        if(j==0)return 1;
        return 0;
    }

    if(dp[i][j][p]!=-1)return dp[i][j][p];

    ll value = 0;

    if(p==0){

        value+=f(i-1 , j , 0);
        value+=f(i-1 , j , 1);
    }

    if(p==1){

        value+=f(i-1 , j-1 , 1);
        value+=f(i-1 , j , 0);
    }

    return dp[i][j][p] = value;
}

int main(void)
{
    memset(dp ,-1 , sizeof(dp));
    while(scanf("%lld %lld",&n , &s)==2){

        if(n<0)break;

        printf("%lld\n",f(n , s , 1));
    }
    return 0;
}
