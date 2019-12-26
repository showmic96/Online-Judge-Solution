// In the name of Allah the Lord of the Worlds.

#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>
using namespace std;

typedef long long ll;
vector<int>edges[1005];
bool vis[1005][1005];
int counter = 0;

void dfs(int st , int u)
{
    if(vis[st][u]==true)return ;
    vis[st][u] = true;
    for(int i=0;i<edges[u].size();i++)dfs(st , edges[u][i]);
}

int main(void)
{
    int n , m , cur = 0 , ans = 0;
    scanf("%d %d",&n , &m);
    for(int i=0;i<m;i++){
        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        edges[in1].push_back(in2);
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            vis[i][j] = false;
        }
    }
    for(int i=1;i<=n;i++){
        dfs(i , i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i][j]==true||vis[j][i]==true)continue;
            ans++;
        }
    }
    printf("%d\n",ans/2);
    return 0;
}
