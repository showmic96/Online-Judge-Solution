// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 10005;
const ll INF = 1e18;

vector<pair<ll , ll > > edges[MAX+9];
ll dis[MAX+9];

void Dijkstra(ll now)
{
    priority_queue<pair<ll , ll > > pq;
    dis[now] = 0;
    pq.push(make_pair(0 , now));
    while(!pq.empty()){

        ll u = pq.top().second;
        ll c1 = -pq.top().first;
        pq.pop();

        if(c1>dis[u])continue;

        for(auto t : edges[u]){

            ll v = t.first;
            ll c = t.second;

            if(dis[v]>dis[u]+c){

                dis[v] = dis[u]+c;
                pq.push(make_pair(-dis[v] , v));
            }
        }
    }
}

int main(void)
{
    string ar;
    while(getline(cin , ar)){

        if(ar==""){

            for(int i=0;i<=MAX;i++)dis[i] = INF;
            Dijkstra(1);

            ll next = -1 , mx = 0;

            for(int i=1;i<=MAX;i++){

                if(dis[i]!=INF){

                    if(mx<dis[i]){

                        mx = dis[i];
                        next = i;
                    }
                }
            }

            for(int i=0;i<=MAX;i++)dis[i] = INF;
            Dijkstra(next);

            mx = 0;
            for(int i=1;i<=MAX;i++){

                if(dis[i]!=INF)mx = max(mx , dis[i]);
            }

            cout << mx << endl;
            for(int i=0;i<MAX;i++)edges[i].clear();
            continue;
        }

        stringstream ss(ar);
        ll in1 ,in2 , in3;
        ss >> in1;
        ss >> in2;
        ss >> in3;

        edges[in1].push_back(make_pair(in2 , in3));
        edges[in2].push_back(make_pair(in1 , in3));
    }

    for(int i=0;i<=MAX;i++)dis[i] = INF;
    Dijkstra(1);

    ll next = -1 , mx = 0;

    for(int i=1;i<=MAX;i++){

        if(dis[i]!=INF){

            if(mx<dis[i]){

                mx = dis[i];
                next = i;
            }
        }
    }

    for(int i=0;i<=MAX;i++)dis[i] = INF;
    Dijkstra(next);

    mx = 0;
    for(int i=1;i<=MAX;i++){

        if(dis[i]!=INF)mx = max(mx , dis[i]);
    }

    cout << mx << endl;
    for(int i=0;i<MAX;i++)edges[i].clear();


    return 0;
}
