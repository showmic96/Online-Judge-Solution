// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int dp[105][205];
int st , en , d;
vector<int>edges[105];

int f(int u , int r)
{
    if(r==0){

        if(u==en)return 1;
        return 0;
    }

    if(dp[u][r]!=-1)return dp[u][r];
    dp[u][r] = 0;

    int si =edges[u].size();
    int value = 0;

    for(int i=0;i<si;i++){

        value = max(value , f(edges[u][i] , r-1));
    }

    return dp[u][r] = value;
}

int main(void)
{
    int n , m;
    while(scanf("%d %d",&n, &m)==2){

        if(!n&&!m)break;
        memset(dp , -1 , sizeof(dp));
        for(int i=0;i<=n;i++)edges[i].clear();

        for(int i=0;i<m;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);

            edges[in1].push_back(in2);
            edges[in2].push_back(in1);
        }

        scanf("%d %d %d",&st , &en , &d);

        int ans = f(st , d);
        if(ans==1)printf("Yes, Teobaldo can travel.\n");
        else printf("No, Teobaldo can not travel.\n");
    }
    return 0;
}
