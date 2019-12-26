// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 3e5+9;
struct s{

    ll d , w , idx;
    s(ll _d , ll _w , ll _idx){

        d = _d;
        w = _w;
        idx = _idx;
    }
};

vector<s>edges[MAX];
ll dis[MAX] , counter = 0 , par[MAX] , cost[MAX];
bool vis[MAX];
set<int>ans;
map<pair<int , int> , int>mp;

void Dijkstra(int u)
{
    priority_queue<pair<ll , ll > >pq;
    for(int i=0;i<MAX;i++)dis[i] = 1e18;

    pq.push({0 , u});
    dis[u] = 0;
    while(!pq.empty()){

        ll c = -pq.top().first;
        u = pq.top().second;
        pq.pop();

        //if(c>dis[u])return ;

        for(auto it : edges[u]){

            int v = it.d;
            c = it.w;

            if(dis[v]>dis[u]+c){

                dis[v] = dis[u]+c;
                pq.push({-dis[v] , v});
            }
        }
    }
}

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);
    for(int i=0;i<m;i++){

        ll in1 , in2 , in3;
        scanf("%lld %lld %lld",&in1 , &in2 , &in3);
        edges[in1].push_back(s(in2 , in3 , i+1));
        edges[in2].push_back(s(in1 , in3 , i+1));

        mp[{in1 , in2}] = i+1;
        mp[{in2 , in1}] = i+1;

    }

    int st;
    scanf("%d",&st);
    Dijkstra(st);

    for(int i=1;i<=n;i++){

        bool found = false;
        ll mi = 1e18;
        ll e = 0;
        for(int j=0;j<edges[i].size();j++){

            ll k = edges[i][j].d;
            ll c = edges[i][j].w;

            if(dis[i]==dis[k]+c && mi>c){

                found = true;
                mi = c;
                e = k;
            }
        }

        if(found==true)ans.insert(mp[{i , e}]) , counter+=mi;
    }

    printf("%lld\n",counter);
    for(auto it : ans)printf("%d ",it);

    return 0;
}
