// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int>edges[205];
int deg[205];
bool vis[205];

void dfs(int u)
{
    if(vis[u])return ;
    vis[u] = true;
    for(auto v:edges[u]){
        dfs(v);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n , m;
    while(cin >> n >> m){
        for(int i=0;i<=n;i++)edges[i].clear() , deg[i] = 0;
        int in1 , in2;
        for(int i=0;i<m;i++){
            cin >> in1 >> in2;
            if(in1==in2)continue;
            edges[in1].push_back(in2);
            edges[in2].push_back(in1);
            deg[in1]++;deg[in2]++;
        }
        memset(vis , false ,sizeof(vis));
        dfs(in1);
        bool possible = true;
        if(m==0)possible = false;
        for(int i=0;i<n;i++){
            if(deg[i]%2)possible = false;
            if(vis[i]==false&&deg[i])possible=false;
        }
        if(possible)cout << "Possible" << endl;
        else cout << "Not Possible" << endl;
    }
    return 0;
}
