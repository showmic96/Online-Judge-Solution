// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;
const ll INF = 1e18;
ll dis[3][MAX];
vector<pair<ll , ll > >edges[MAX];

void Dijkstra(int i , int st)
{
    priority_queue<pair<ll , ll> > pq;
    dis[i][st] = 0;
    pq.push({0 , st});
    while(!pq.empty()){
        ll u = pq.top().second;
        ll c = -pq.top().first;
        pq.pop();
        if(c>dis[i][u])continue;
        for(auto it:edges[u]){
            ll v = it.first;
            c = it.second;
            if(dis[i][v]>dis[i][u]+c){
                dis[i][v] = dis[i][u]+c;
                pq.push({-dis[i][v] , v});
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        for(int i=0;i<MAX;i++){
            edges[i].clear();
            dis[0][i] = INF;
            dis[1][i] = INF;
            dis[2][i] = INF;
        }
        int n , m , s , t , v;
        cin >> n >> m;
        cin >> s >> t >> v;
        for(int i=0;i<m;i++){
            ll in1 , in2 , in3;
            cin >> in1 >> in2 >> in3;
            edges[in1].push_back({in2 , in3});
            edges[in2].push_back({in1 , in3});
        }
        Dijkstra(0 , s);
        Dijkstra(1 , t);
        Dijkstra(2 , v);
        ll ans = 1e18;
        for(int i=1;i<=n;i++){
            ans = min(ans , dis[0][i]+dis[1][i]+dis[2][i]);
        }
        cout << ans << endl;
    }

    return 0;
}
