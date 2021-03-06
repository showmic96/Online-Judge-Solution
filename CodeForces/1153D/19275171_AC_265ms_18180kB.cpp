// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 3e5+9;
vector<int>edges[MAX+9];
int dp[MAX+9] , ar[MAX+9] , cnt = 0;
int dfs(int u, int par)
{
    if(edges[u].size()==1&&u!=1){cnt++;dp[u] = 1;return 1;}
    vector<int>temp;
    for(auto v:edges[u]){
        if(v!=par){
            temp.push_back(dfs(v , u));
        }
    }
    if(ar[u]==0){
        for(auto it:temp)dp[u]+=it;
    }
    else{
        int mi = 1e9;
        for(auto it:temp)mi = min(mi , it);
        dp[u] = mi;
    }
    return dp[u];
}

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
    for(int i=2;i<=n;i++){
        int in;
        scanf("%d",&in);
        edges[in].push_back(i);
        edges[i].push_back(in);
    }
    int ans = cnt - dfs(1 , 0);
    printf("%d\n",cnt-dp[1]+1);
    return 0;
}
