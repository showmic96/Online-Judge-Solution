// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 9 , INF = 1e9;

vector<pair <int , int> > edges[MAX+9];
int dis[MAX+9];

void setUp(int n)
{
    for(int i=0;i<=n;i++){

        edges[i].clear();
        dis[i] = INF;
    }
}

void Dijkstra(int i)
{
    priority_queue<pair < int , int > > pq;

    dis[i] = 0;

    pq.push(make_pair(0 , i));

    while(!pq.empty()){

        int u = pq.top().second;
        int c1 = -pq.top().first;

        pq.pop();

        int si = edges[u].size();

        for(int j=0;j<si;j++){

            int v = edges[u][j].first;
            int c = edges[u][j].second;

            if(dis[v]>dis[u]+c){

                dis[v] = dis[u] + c;

                pq.push(make_pair(-dis[v] , v));
            }
        }
    }
}

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        int n , m;
        cin >> n >> m;
        setUp(n);

        while(m--){

            int in1 , in2 , in3;
            cin >> in1 >> in2 >> in3;

            edges[in1].push_back(make_pair(in2 , in3));
        }

        int st , en;
        cin >> st >> en;

        Dijkstra(st);

        if(dis[en]==INF)cout << "NO" << endl;
        else cout << dis[en] << endl;

    }

    return 0;
}
