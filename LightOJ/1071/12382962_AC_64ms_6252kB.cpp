// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int dp[105][105][105];
int ar[105][105] , n , m;

int f(int r1 , int c1 , int r2 , int c2)
{
    if(r1>=n||r2>=n||c1>=m||c2>=m)return 0;
    if(r1==r2&&c1==c2){
        if(r1==n-1&&c1==m-1)return ar[r1][c1];
        return 0;
    }

    if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];

    int value = 0;

    value = max(value , f(r1+1 , c1 , r2+1 , c2));
    value = max(value , f(r1+1 , c1 , r2 , c2+1));
    value = max(value , f(r1 , c1+1 , r2+1 , c2));
    value = max(value , f(r1 , c1+1 , r2 , c2+1));

    return dp[r1][c1][r2] = value+ar[r1][c1]+ar[r2][c2];
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));

        scanf("%d %d",&n , &m);

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                scanf("%d",&ar[i][j]);
            }
        }

        printf("Case %d: %d\n",++c , f(0 , 1 , 1 , 0)+ar[0][0]);
    }
    return 0;
}
