// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[1000005];
int k , l , m;

bool isWinning(int pos) {

        if(pos==1)return true;
        if(pos==k)return true;
        if(pos==l)return true;

        if(dp[pos]!=-1)return dp[pos];

        if(pos-1>0)if (!isWinning(pos-1)) return dp[pos] = true;
        if(pos-k>0)if (!isWinning(pos-k)) return dp[pos] = true;
        if(pos-l>0)if (!isWinning(pos-l)) return dp[pos] = true;

        return dp[pos] = false;
}

int main(void)
{
    int t;
    scanf("%d %d %d",&k, &l , &m);

    memset(dp , -1 , sizeof(dp));

    while(m--){

        int n;
        scanf("%d",&n);

        if(isWinning(n)==true)printf("A");
        else printf("B");
    }
    printf("\n");

    return 0;
}
