// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[110];

bool isWinning(int pos) {

        if(pos==2)return true;
        if(pos==3)return true;
        if(pos==5)return true;

        if(dp[pos]!=-1)return dp[pos];

        if(pos-2>0)if (!isWinning(pos-2)) return dp[pos] = true;
        if(pos-3>0)if (!isWinning(pos-3)) return dp[pos] = true;
        if(pos-5>0)if (!isWinning(pos-5)) return dp[pos] = true;

        return dp[pos] = false;
}

int main(void)
{
    int t;
    scanf("%d",&t);

    memset(dp , -1 , sizeof(dp));

    while(t--){

        int n;
        scanf("%d",&n);

        if(isWinning(n)==true)printf("First\n");
        else printf("Second\n");
    }

    return 0;
}
