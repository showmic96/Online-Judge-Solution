// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2005;
int mat[MAX][MAX] , n;
bool vis[MAX] , check = true , taken[MAX][MAX];
ll dis[MAX];
vector<pair<ll , ll> > edges[MAX];
struct s{
    int u , v , w;
    s(int _u , int _v , int _w){
        u = _u;
        v = _v;
        w = _w;
    }
};
bool cmp(s A , s B)
{
    return A.w < B.w;
}
vector<s>v;
int par[MAX];

void Dijkstra(int st)
{
    for(int i=1;i<=n;i++)dis[i] = 1e18;
    priority_queue<pair<ll , ll > >pq;
    pq.push({0 , st});
    dis[st] = 0;
    while(!pq.empty()){
        ll c = -pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        for(auto it:edges[u]){
            ll v = it.first;
            c = it.second;
            if(dis[v]>dis[u]+c){
                dis[v] = dis[u]+c;
                pq.push({-dis[v] , v});
            }
        }
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
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    memset(taken , false , sizeof(taken));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mat[i][j]!=mat[j][i])check = false;
            if(taken[i][j]==false&&mat[i][j]>0){
                taken[i][j] = true;
                taken[j][i] = true;
                v.push_back(s(i , j , mat[i][j]));
            }
        }
    }
    for(int i=1;i<=n;i++)par[i] = i;
    sort(v.begin() , v.end() , cmp);
    for(int i=0;i<v.size();i++){
        if(Find(v[i].u)==Find(v[i].v))continue;
        edges[v[i].u].push_back({v[i].v , v[i].w});
        edges[v[i].v].push_back({v[i].u , v[i].w});
        Union(v[i].u , v[i].v);
    }
    for(int i=1;i<=n;i++){
        Dijkstra(i);
        for(int j=1;j<=n;j++){
            if(dis[j]!=mat[i][j])check = false;
        }
        if(check==false)break;
    }
    if(check)printf("YES\n");
    else printf("NO\n");
    return 0;
}
