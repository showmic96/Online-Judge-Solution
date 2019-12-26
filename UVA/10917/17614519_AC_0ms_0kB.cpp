// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1005;
const ll INF = 1e18;

int n , m;
vector<pair<ll , ll> > edges[MAX+9];
ll dis[MAX+9] , dp[MAX+9];

void Dijkstra()
{
    priority_queue<pair<ll , ll> > pq;
    dis[2] = 0;
    pq.push({0 , 2});
    while(!pq.empty()){

        ll u = pq.top().second;
        ll c = -pq.top().first;

        pq.pop();

        if(c>dis[u])continue;

        for(auto it : edges[u]){

            ll v = it.first;
            c = it.second;

            if(dis[v]>dis[u]+c){

                dis[v] = dis[u]+c;
                pq.push({-dis[v] , v});
            }
        }
    }
}

ll f(int u)
{
    if(u==1)return 1;
    if(dp[u]!=-1)return dp[u];

    ll value = 0;

    for(auto v:edges[u]){

        if(dis[v.first]>dis[u])value+=f(v.first);
    }

    return dp[u] = value;
}

int main(void)
{
    while(scanf("%d",&n)==1){

        if(n==0)break;
        scanf("%d",&m);

        for(int i=0;i<=n;i++){

            edges[i].clear();
            dis[i] = INF;
        }

        for(int i=0;i<m;i++){

            ll in1 , in2 , in3;
            scanf("%lld %lld %lld",&in1 , &in2 , &in3);
            edges[in1].push_back({in2 , in3});
            edges[in2].push_back({in1 , in3});
        }

        Dijkstra();
        memset(dp , -1 , sizeof(dp));
        printf("%lld\n",f(2));
    }
    return 0;
}
