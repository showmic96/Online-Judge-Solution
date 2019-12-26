// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll dp[55][55];
int ar[55];

ll f(int i , int j)
{
    if(i==0){

        if(j==0)return 1;
        return 0;
    }

    if(dp[i][j]!=-1)return dp[i][j];

    ll value = 0;

    for(int i1=0;i1<=ar[i];i1++){

        if(j-i1>=0)value+=f(i-1 , j-i1);
    }

    return dp[i][j] = value;
}

int main(void)
{
    int c = 0 , n , m;

    while(scanf("%d %d",&n , &m)==2){

        if(!n&&!m)break;

        memset(ar , 0 , sizeof(ar));
        memset(dp , -1 , sizeof(dp));

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            ar[in]++;
        }
        printf("Case %d:\n",++c);
        for(int i=0;i<m;i++){

            int in;
            scanf("%d",&in);
            printf("%llu\n",f(n ,in));
        }
    }
    return 0;
}
