// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , dp[2005][4005];
ll fib[100];

int f(int i , int j)
{
    if(i==0){

        if(j==0)return 1;

        return 0;
    }

    if(dp[i][j]!=-1)return dp[i][j];

    int value = 0;

    for(int i1=20;i1>=0;i1--){

        if(i-fib[i1]>=0&&j-fib[i1+1]>=0)value = max(value , f(i-fib[i1] , j-fib[i1+1]));
    }

    return dp[i][j] = value;
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));
    fib[0] = 0;
    fib[1] = 1;

    for(int i=2;i<100;i++)fib[i] = fib[i-1]+fib[i-2];
    for(int i=1;i<=2000;i++){

        for(int j=1;j<=4000;j++){

            f(i , j);
        }
    }

    while(scanf("%d",&n)==1){

        if(n==0)break;
        double ans = 1e19;

        for(int i=1;i<=4000;i++){

            if(dp[n][i]==1){

                ans = min(ans , abs(i-1.6*(double)n));
            }
        }

        printf("%.2f\n",ans);
    }
    return 0;
}
