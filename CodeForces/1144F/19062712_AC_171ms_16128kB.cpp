// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int>edges[200005];
int dir[200005] , color[200005];
int vis[200005];
bool check = true;

void dfs(int u , int now = 0)
{
    if(vis[u]!=-1){if(vis[u]!=now)check = false;return ;}
    vis[u] = now;
    for(auto v: edges[u]){
        dfs(v , now^1);
    }
}

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);
    vector<pair<int , int> > v;
    for(int i=0;i<m;i++){
        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
        v.push_back({in1 , in2});
    }
    memset(vis , -1 , sizeof(vis));
    dfs(1);
    if(check==false)printf("NO\n");
    else{
        printf("YES\n");
        for(int i=0;i<m;i++){
            printf("%d",vis[v[i].first]);
        }
        printf("\n");
    }
    return 0;
}
