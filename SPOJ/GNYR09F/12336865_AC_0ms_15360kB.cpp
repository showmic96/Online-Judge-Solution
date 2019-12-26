// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[105][105][2];
int c , n , m;

ll f(int i , int len , int now)
{
    if(i==n){

        if(len==m)return 1;
        return 0;
    }

    if(dp[i][len][now]!=-1)return dp[i][len][now];

    ll value = 0;

    if(now==1){

        value+=f(i+1 , len+1 , 1);
        value+=f(i+1 , len , 0);
    }

    else{

        value+=f(i+1 , len , 1);
        value+=f(i+1 , len , 0);
    }

    return dp[i][len][now] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--){

        memset(dp , -1 , sizeof(dp));
        scanf("%d %d %d",&c , &n , &m);

        printf("%d %lld\n",c , f(0 , 0 , 0));
    }

    return 0;
}
