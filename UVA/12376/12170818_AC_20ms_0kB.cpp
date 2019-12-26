// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 105;
vector<int>edges[MAX+9];
vector<int>v;
int counter , last;
bool vis[MAX+9];

void dfs(int u)
{
    if(vis[u]==true)return ;
    vis[u] = true;

    counter+=v[u];
    last = u;

    int si = edges[u].size() , mx = 0;

    for(int i=0;i<si;i++){

        mx = max(mx , v[edges[u][i]]);
    }

    for(int i=0;i<si;i++){

        if(mx==v[edges[u][i]])dfs(edges[u][i]);
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , m;
        scanf("%d %d",&n , &m);

        v.clear();
        memset(vis , false, sizeof(vis));

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        for(int i=0;i<=n;i++){

            edges[i].clear();
        }

        for(int i=0;i<m;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            edges[in1].push_back(in2);
        }

        counter = 0;

        dfs(0);

        printf("Case %d: %d %d\n",++c , counter , last);
    }
    return 0;
}
