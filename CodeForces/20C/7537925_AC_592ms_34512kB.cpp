#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e15 , MAX = 1000010;
typedef long long ll;

vector<pair<ll ,ll > > edges[MAX+1];
ll cost[MAX+1];
ll parent[MAX+1];

void setUp(ll x)
{

    for(ll i=0;i<=x;i++){

        cost[i]=INF;
        edges[i].clear();
    }

}

void print(ll x)
{
    if(x>1)print(parent[x]);

    cout << x << " ";
}

void Dijkstra(ll n)
{
    priority_queue<pair<ll ,ll> > current;

    current.push(make_pair(0,1));

    parent[1]=1;

    cost[1]=0;

    while(!current.empty()){

        int u = current.top().second , v = -current.top().first;

        current.pop();

       // if(v>cost[u])continue;

        ll si = edges[u].size();

        for(ll i=0;i<si;i++){


            ll temp1 = edges[u][i].first , temp2 = edges[u][i].second;

            if(cost[temp1]>temp2+cost[u]){

                cost[temp1]=temp2+cost[u];

                current.push(make_pair(-cost[temp1],temp1));

                parent[temp1] = u;
            }
        }

    }

    if(cost[n]==INF)cout << -1 << endl;
    else print(n);

}


int main(void)
{
    ll n , m;
    cin >> n >> m;

    ll u , v , c;

    setUp(max(n,m));

    while(m--){

        cin >> u >> v >> c;

        edges[u].push_back(make_pair(v,c));
        edges[v].push_back(make_pair(u,c));
    }
    Dijkstra(n);

    cout << endl;

    return 0;
}