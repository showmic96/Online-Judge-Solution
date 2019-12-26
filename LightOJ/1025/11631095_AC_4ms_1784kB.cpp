// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[110][110];

char ar[110];

ll f(int i , int j)
{
    if(i>j)return 0;
    if(i==j)return 1;

    if(dp[i][j]!=-1)return dp[i][j];

    ll value = 0;

    if(ar[i]==ar[j]){

        value = f(i+1 , j) + f(i , j-1) + 1;
    }

    else{

        value = f(i+1 , j) + f(i , j-1) - f(i+1 , j-1);
    }

    return dp[i][j] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        memset(dp , -1 , sizeof(dp));

        scanf("%s",&ar);
        int si = strlen(ar) - 1;
        printf("Case %d: %lld\n",++c , f(0 , si));
    }
    return 0;
}
