// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int dp[6101][6101];
char ar[6105];

int f(int i , int j)
{
    if(i>=j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int value = 1234567;

    value = f(i+1 , j)+1;
    value = min(value , f(i , j-1)+1);
    if(ar[i]==ar[j])value = min(value , f(i+1 , j-1));

    return dp[i][j] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));

        scanf("%s",&ar);
        printf("%d\n",f(0 , strlen(ar)-1));
    }
    return 0;
}
