// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

vector<int>edges[1005];
int ans[1005];
bool visited[1005];

void dfs(int u)
{
    visited[u] = true;

    int si = edges[u].size();

    for(int i=0;i<si;i++){

        if(visited[edges[u][i]]==true)continue;

        dfs(edges[u][i]);
        ans[u]^=(ans[edges[u][i]]+1);
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        memset(ans , 0 , sizeof(ans));
        memset(visited , false , sizeof(visited));

        int n;
        scanf("%d",&n);

        for(int i=0;i<=n;i++)edges[i].clear();

        for(int i=0;i<n-1;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            edges[in1].push_back(in2);
            edges[in2].push_back(in1);
        }

        dfs(1);

        if(ans[1]==0)printf("Bob\n");
        else printf("Alice\n");
    }

    return 0;
}
