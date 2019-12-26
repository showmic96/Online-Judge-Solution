// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[105][105];

char ar[105];

ll f(int i , int j)
{
    if(i>=j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    ll value = 0;

    if(ar[i]==ar[j]){

        value = f(i+1 , j-1);
    }

    else{

        value = f(i+1 , j)+1;
        value = min(value , f(i , j-1)+1);
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

        printf("Case %d: %lld\n",++c , f(0 , strlen(ar)-1));
    }
    return 0;
}
