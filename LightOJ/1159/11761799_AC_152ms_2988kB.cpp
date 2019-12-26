// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[55][55][55];
char ar[55] , br[55] , cr[55];

int si1 , si2 , si3;

ll f(int i , int j , int k)
{
    if(i==si1||j==si2||k==si3)return 0;

    if(dp[i][j][k]!=-1)return dp[i][j][k];

    ll value = 0;

    if(ar[i]==br[j]&&ar[i]==cr[k]){

        value = f(i+1 ,j+1 , k+1)+1;
    }

    else{

        value = f(i+1 , j , k);
        value = max(value , f(i , j+1 , k));
        value = max(value , f(i , j , k+1));
    }

    return dp[i][j][k] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));

        scanf("%s %s %s",&ar , &br ,&cr);

        si1 = strlen(ar);
        si2 = strlen(br);
        si3 = strlen(cr);

        printf("Case %d: %lld\n",++c , f(0 , 0 , 0));
    }
    return 0;
}
