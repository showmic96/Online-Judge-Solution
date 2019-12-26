// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e5+9;
vector<int>edges[MAX] , re[MAX];
int counter = 0 , dp[MAX];

void dfs1(int u , int par = -1 , int dir = 0)
{
    if(dir==1)counter++;
    for(auto v:edges[u]){
        if(v!=par)dfs1(v , u , 0);
    }
    for(auto v:re[u]){
        if(v!=par)dfs1(v , u , 1);
    }
}
void dfs2(int u , int par = -1 , int tot = 0 , int dis = 0)
{
    dp[u] = counter-2*tot+dis;
    for(auto v:edges[u]){
        if(v!=par)dfs2(v , u , tot , dis+1);
    }
    for(auto v:re[u]){
        if(v!=par)dfs2(v , u , tot+1 , dis+1);
    }
}

int main(void)
{
    int n , mi = 1e9;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        edges[in1].push_back(in2);
        re[in2].push_back(in1);
    }
    dfs1(1);
    dfs2(1);
    for(int i=1;i<=n;i++)mi = min(dp[i] , mi);
    printf("%d\n",mi);
    for(int i=1;i<=n;i++)if(dp[i]==mi)printf("%d ",i);

    return 0;
}
