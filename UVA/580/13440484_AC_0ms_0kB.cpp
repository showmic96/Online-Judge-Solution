// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll dp[33][33][3];

ll f(int i ,int l, int now)
{
    if(i==n){
        if(now==1)return 1;
        if(l>=3)return 1;
        return 0;
    }

    if(dp[i][l][now]!=-1)return dp[i][l][now];
    ll value = 0;

    if(l>=3){

        value+=f(i+1 , l+1 , 1);
        value+=f(i+1 , 0 , 1);
    }
    else{

        value+=f(i+1 , l+1 , now);
        value+=f(i+1 , 0 , now);
    }

    return dp[i][l][now] = value;
}

int main(void)
{

    while(scanf("%d",&n)==1){

        if(n==0)break;
        memset(dp , -1 , sizeof(dp));

        printf("%lld\n",f(0 , 0 , 0));
    }
    return 0;
}
