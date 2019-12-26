// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5+9;
const ll INF = 1e18;
vector<pair<ll , ll> > edges[MAX+9] , v , r[MAX+9];
ll dis[MAX+9];
bool vis[MAX+9];

void Dijkstra()
{
    priority_queue<pair<ll , ll > >pq;
    dis[1] = 0;
    pq.push({0 , 1});
    while(!pq.empty()){
        ll u = pq.top().second;
        ll c = -pq.top().first;
        pq.pop();
        if(c>dis[u])continue;

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

int main(void)
{
    int n , m , k , counter = 0;
    scanf("%d %d %d",&n , &m , &k);
    for(int i=0;i<m;i++){
        ll in1 , in2 , in3;
        scanf("%lld %lld %lld",&in1 , &in2 , &in3);
        edges[in1].push_back({in2 , in3});
        edges[in2].push_back({in1 , in3});
        r[in1].push_back({in2 , in3});
        r[in2].push_back({in1 , in3});
    }
    for(int i=0;i<k;i++){
        ll in1 ,in2;
        scanf("%lld %lld",&in1 , &in2);
        edges[1].push_back({in1 , in2});
        edges[in1].push_back({1 , in2});
        v.push_back({in1 , in2});
    }
    for(int i=1;i<=n;i++)dis[i] = INF;
    Dijkstra();
    memset(vis , false , sizeof(vis));
    for(int i=1;i<=n;i++){
        for(auto it : r[i]){
            ll u = it.first;
            ll c = it.second;
            if(dis[u] == dis[i]+c)vis[u] = true;
        }
    }
    for(auto it : v){
        ll u = it.first;
        ll c = it.second;
        if(vis[u]==true)counter++;
        else{
            if(dis[u]==c)vis[u] = true;
            else counter++;
        }
    }
    printf("%d\n",counter);
    return 0;
}
