// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 150005;
vector<int>edges[MAX+9];
int par[MAX+9];

void dfs(int u , int par = -1)
{
    printf("%d ",u);
    for(auto v : edges[u]){
        if(v!=par)dfs(v , u);
    }
}

int Find(int x)
{
    if(x==par[x])return x;
    return par[x] = Find(par[x]);
}
void Union(int x , int y)
{
    int px = Find(x);
    int py = Find(y);

    par[py] = px;
}

int main(void)
{
    int n , st = -1;
    scanf("%d",&n);

    for(int i=0;i<=n;i++)par[i] = i;

    for(int i=0;i<n-1;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        int u = Find(in1) , v = Find(in2);

        edges[u].push_back(v);
        edges[v].push_back(u);

        Union(u , v);
        st = u;
    }

    dfs(st);

    return 0;
}
