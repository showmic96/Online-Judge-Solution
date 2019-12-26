// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;
const ll INF = 1234567891011121314;

ll dp[MAX+9][3];
ll ar[MAX+9][3];

int n ;

ll f(int i , int j)
{
    if(i==n-1&&j==1){

        return ar[i][j];
    }
    if(i>n)return INF;

    if(dp[i][j]!=-INF)return dp[i][j];

    ll value = INF;

    if(j==0){

        value = f(i+1 ,j) + ar[i][j];
        value = min(value , f(i , j+1) + ar[i][j]);
        value = min(value , f(i+1, j+1) + ar[i][j]);

    }

    if(j==1){

        value = f(i+1 ,j) + ar[i][j];
        value = min(value , f(i , j+1) + ar[i][j]);
        value = min(value , f(i+1, j+1) + ar[i][j]);
        value = min(value , f(i+1, j-1) + ar[i][j]);

    }

    if(j==2){

        value = f(i+1 ,j) + ar[i][j];
        value = min(value , f(i+1, j-1) + ar[i][j]);
    }

    return dp[i][j] = value;
}

int main(void)
{
    int c = 0;
    while(scanf("%d",&n)==1){

        if(!n)break;

        for(int i=0;i<MAX;i++)
            for(int j=0;j<3;j++)
                dp[i][j] = -INF;

        for(int i=0;i<n;i++){

            for(int j=0;j<3;++j){

                scanf("%lld",&ar[i][j]);
            }
        }

        printf("%d. %lld\n",++c , f(0 , 1));
    }
    return 0;
}
