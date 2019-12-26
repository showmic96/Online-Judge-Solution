// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 55;
vector<pair<int , ll> > edges[MAX+9] , v;
ll dis[MAX][MAX];
ll dp[55][(1<<12)+10];
bool vis[55][(1<<12)+10];

bool Check(int n , int pos)
{
    return n&(1<<pos);
}
int Set(int n , int pos)
{
    return n|(1<<pos);
}

ll f(int now , int mask)
{
    if(vis[now][mask]==true)return dp[now][mask];
    vis[now][mask] = true;
    ll value = -dis[now][0];
    for(int i=0;i<v.size();i++){
        if(Check(mask , i)==false){
            value = max(value , f(v[i].first , Set(mask , i))+v[i].second-dis[now][v[i].first]);
        }
    }
    return dp[now][mask] = value;
}

void Dijkstra(int st)
{
    priority_queue<pair<ll , int> > pq;
    dis[st][st] = 0;
    pq.push({0 , st});
    while(!pq.empty()){
        ll c = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for(auto it:edges[u]){
            int v = it.first;
            c =  it.second;
            if(dis[st][v]>dis[st][u]+c){
                dis[st][v] = dis[st][u]+c;
                pq.push({-dis[st][v] , v});
            }
        }
    }
}
int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        v.clear();
        int n , m;
        scanf("%d %d",&n , &m);
        for(int i=0;i<=n;i++)edges[i].clear();
        for(int i=0;i<m;i++){
            int in1 , in2 , in3 , in4;
            scanf("%d %d %d.%d",&in1 , &in2 , &in3,&in4);
            ll t = in3*100+in4;
            edges[in1].push_back({in2 , t});
            edges[in2].push_back({in1 , t});
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dis[i][j] = 1e18;
            }
        }
        for(int i=0;i<=n;i++){
            Dijkstra(i);
        }
        int p;
        scanf("%d",&p);
        for(int i=0;i<p;i++){
            int in1 , in2 , in3;
            scanf("%d %d.%d",&in1 , &in2 , &in3);
            ll temp = in2*100+in3;
            v.push_back({in1 , temp});
        }
        memset(vis , false , sizeof(vis));
        ll ans = 0;
        for(int i=0;i<p;i++){
            ans = max(ans , f(v[i].first , Set(0 , i))+v[i].second-dis[0][v[i].first]);
        }
        if(ans<=0)printf("Don't leave the house\n");
        else printf("Daniel can save $%lld.%02lld\n",ans/100 , ans%100);
    }
    return 0;
}
