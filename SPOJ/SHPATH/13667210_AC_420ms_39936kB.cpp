// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 200000+9;
ll INF = 123456789011121314;

ll dis[MAX+9];
vector<pair<ll , ll > >edges[MAX+9];

void dijkstra(int st , int en)
{
    priority_queue<pair<ll , ll > > pq;
    dis[st] = 0;
    pq.push(make_pair(0 , st));

    while(!pq.empty()){

        int u = pq.top().second;
        int si = edges[u].size();
        pq.pop();

        if(u==en)break;

        for(int i=0;i<si;i++){

            ll v = edges[u][i].first;
            ll c = edges[u][i].second;

            if(dis[v]>dis[u]+c){

                dis[v] = dis[u]+c;
                pq.push(make_pair(-dis[v] , v));
            }
        }
    }

    cout << dis[en] << endl;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;

        map<string , int>mp;

        for(int i=0;i<=n;i++){

            edges[i].clear();
            dis[i] = INF;
        }

        for(int i=0;i<n;i++){

            string name;
            cin >> name;

            mp[name] = i+1;

            int m;
            cin >> m;

            for(int j=0;j<m;j++){

                int in1 , in2;
                cin >> in1 >> in2;

                edges[i+1].push_back(make_pair(in1 , in2));
                edges[in1].push_back(make_pair(i+1 , in2));
            }
        }

        int q;
        cin >> q;

        while(q--){

            string ar , br;
            cin >> ar >> br;

            for(int i=0;i<=n;i++)dis[i] = INF;

            dijkstra(mp[ar] , mp[br]);
        }
    }
    return 0;
}
