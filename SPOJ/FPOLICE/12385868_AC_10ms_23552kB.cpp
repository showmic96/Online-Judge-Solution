// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int dp[105][20055];
int n , ti[105][105] , r[105][105] , total;

int f(int i , int t)
{
    if(i==n-1)return 0;
    if(dp[i][t]!=-1)return dp[i][t];
    dp[i][t] = 0;

    int value = 12345678;
    for(int i1=0;i1<n;i1++){

        if(i==i1)continue;

        if(t-ti[i][i1]>=0){

            value = min(value , f(i1 , t-ti[i][i1])+r[i][i1]);
        }
    }

    return dp[i][t] = value;
}

int ff(int i , int t)
{
    if(i==n-1){

        if(t==0)return 0;
        return 12345678;
    }
    if(dp[i][t]!=-1)return dp[i][t];
    dp[i][t] = 0;

    int value = 12345678;
    for(int i1=0;i1<n;i1++){

        if(i==i1)continue;

        if(t-r[i][i1]>=0){

            value = min(value , ff(i1 , t-r[i][i1])+ti[i][i1]);
        }
    }

    return dp[i][t] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&n , &total);
        int ans = 0;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                scanf("%d",&ti[i][j]);
            }
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                scanf("%d",&r[i][j]);
            }
        }

        memset(dp , -1 , sizeof(dp));

        ans = f(0 , total);

        if(ans>1234567)printf("-1\n");
        else{

            printf("%d",ans);

            memset(dp , -1 , sizeof(dp));

            printf(" %d\n",ff(0, ans));
        }
    }
    return 0;
}
