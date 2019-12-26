// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 12;
ll dp[MAX][MAX];
ll ar[MAX];
int m , n;

ll f(int i , int v)
{
    if(i==n)return 1;

    if(dp[i][v]!=-1)return dp[i][v];

    ll value = 0;

    for(int j=0;j<m;j++){

        if(i==0){

            value+=f(i+1 , ar[j]);
        }

        else{

            if(abs(ar[j]-v)<=2)value+=f(i+1 , ar[j]);
        }
    }

    return dp[i][v] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){

        memset(dp , -1 , sizeof(dp));
        scanf("%d %d",&m , &n);

        for(int j=0;j<m;j++){

            scanf("%d",&ar[j]);
        }

        printf("Case %d: %lld\n",i+1  , f(0 , 0));
    }

    return 0;
}
