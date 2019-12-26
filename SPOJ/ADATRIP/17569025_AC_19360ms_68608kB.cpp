// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 5e5+9;
const ll INF = 1e18+9;

ll dis[MAX];
vector<pair<ll , ll> > edges[MAX];
int n , m , q;;

pair<ll , ll> Dijkstra(int parent)
{
    priority_queue<pair<ll ,ll>>pq;
    dis[parent] = 0;
    pq.push(make_pair(0 , parent));

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
                pq.push(make_pair(-dis[v] , v));
            }
        }
    }
    ll mx = 0 , c = 0;

    for(int i=0;i<n;i++){

        if(dis[i]==INF)continue;
        if(dis[i]>mx){

            mx = dis[i];
            c = 1;
        }
        else if(dis[i]==mx){

            c++;
        }
    }
    return make_pair(mx , c);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> q;

    for(int i=0;i<m;i++){

        ll in1 , in2 , in3;
        cin >> in1 >> in2 >> in3;
        edges[in1].emplace_back(in2 , in3);
        edges[in2].emplace_back(in1 , in3);
    }

    while(q--){

        int in;
        cin >> in;

        for(int i=0;i<MAX;i++){

            dis[i] = INF;
        }

        pair<ll , ll>ans = Dijkstra(in);

        cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}
