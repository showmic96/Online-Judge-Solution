// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

char ar[1005];
int dp[1005][1005];

int f(int i , int j)
{
    if(i>=j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int value = 1e9;
    if(ar[i]==ar[j])value = min(value , f(i+1 , j-1));

    value = min(value , f(i+1 , j-1)+1);
    value = min(value , f(i+1 , j)+1);
    value = min(value , f(i , j-1)+1);

    return dp[i][j] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%s",&ar);
        memset(dp , -1 , sizeof(dp));
        printf("Case %d: %d\n",++c , f(0 , strlen(ar)-1));
    }

    return 0;
}
