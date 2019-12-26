// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , m , cost[10005][2];
vector<pair<int , ll> >edges[100005];

void Dijkstra()
{
    priority_queue<pair<ll , pair<int , int > > > pq;
    pq.push(make_pair(0 , make_pair(1 , 0)));

    cost[1][0] = 0;

    while(!pq.empty()){

        ll u = pq.top().second.first;
        int state = pq.top().second.second;
        pq.pop();

        for(int i=0;i<edges[u].size();i++){

            ll v = edges[u][i].first;
            ll c = edges[u][i].second;

            if(cost[v][state^1]>cost[u][state]+c){

                cost[v][state^1] = cost[u][state]+c;
                pq.push(make_pair(-cost[v][state^1] , make_pair(v , state^1)));
            }
        }
    }
}

int main(void)
{
    while(scanf("%lld %lld",&n , &m)==2){

        for(int i=0;i<=n;i++)edges[i].clear();

        for(int i=0;i<m;i++){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);
            edges[in1].push_back(make_pair(in2 , in3));
            edges[in2].push_back(make_pair(in1 , in3));
        }
        for(int i=0;i<=n;i++){

            cost[i][0] = 1e18;
            cost[i][1] = 1e18;
        }

        Dijkstra();

        ll ans = cost[n][0];
        if(ans>=1e9)ans = -1;

        printf("%lld\n",ans);
    }

    return 0;
}
