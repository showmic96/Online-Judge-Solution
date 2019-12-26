// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[105][105];
ll ar[105][105];

bool vis[105][105];
int n , m;

ll f(int i , int j , ll current)
{
    if(i<0||j<0)return 0;
    if(i>=n||j>=n)return 0;

    if(ar[i][j]<=current)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    ll value = 0;

    for(int i1=1;i1<=m;i1++){

        value = max(value , f(i+i1 , j , ar[i][j])+ar[i][j]);
        value = max(value , f(i-i1 , j , ar[i][j])+ar[i][j]);
        value = max(value , f(i , j+i1 , ar[i][j])+ar[i][j]);
        value = max(value , f(i , j-i1 , ar[i][j])+ar[i][j]);
    }

    return dp[i][j] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    bool blank = false;
    while(t--){

        if(blank)printf("\n");blank = true;
        scanf("%d %d",&n , &m);
        memset(dp , -1 , sizeof(dp));

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++)scanf("%lld",&ar[i][j]);
        }

        printf("%lld\n",f(0 , 0 , 0));
    }
    return 0;
}
