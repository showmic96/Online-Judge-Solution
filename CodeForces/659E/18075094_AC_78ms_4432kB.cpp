// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5+9;
vector<int>edges[MAX];
bool vis[MAX] , cycle;

void dfs(int u , int par = -1)
{
    if(vis[u]==true){cycle = true;return ;}
    vis[u] = true;
    for(auto v : edges[u]){
        if(v!=par)dfs(v , u);
    }
}

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);
    for(int i=0;i<m;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }
    memset(vis , false , sizeof(vis));
    int ans = 0;
    for(int i=1;i<=n;i++){

        if(vis[i]==false){

            cycle = false;
            dfs(i);
            if(cycle==false)ans++;
        }
    }
    printf("%d\n",ans);

    return 0;
}
