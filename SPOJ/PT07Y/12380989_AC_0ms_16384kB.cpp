// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

vector<int>edges[10000+9];
bool vis[10000+9];

void dfs(int u)
{
    if(vis[u]==true)return ;
    vis[u] = true;

    int si = edges[u].size();

    for(int i=0;i<si;i++){

        dfs(edges[u][i]);
    }
}

int main(void)
{
    memset(vis , false , sizeof(vis));

    int n , m;
    scanf("%d %d",&n, &m);

    for(int i=0;i<m;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);

        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    if(n!=m+1){

        printf("NO\n");
    }

    else{

        dfs(1);
        bool check = true;
        for(int i=1;i<=n;i++){

            if(vis[i]==false)check = false;
        }

        if(check)printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
