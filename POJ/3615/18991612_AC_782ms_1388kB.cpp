// In the name of Allah the Lord of the Worlds.

#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;

typedef long long ll;
ll dis[305][305];
vector<pair<ll , ll > > edges[305];

void Dijkstra(int st)
{
    priority_queue<pair<ll , ll > > pq;
    pq.push(make_pair(0 , st));
    dis[st][st] = 0;
    while(!pq.empty()){
        ll u = pq.top().second;
        ll c1 = -pq.top().first;
        pq.pop();
        if(dis[st][u]<c1)continue;
        for(int i=0;i<edges[u].size();i++){
            ll v = edges[u][i].first;
            ll c = edges[u][i].second;
            if(dis[st][v]>max(dis[st][u] , c)){
                dis[st][v] = max(dis[st][u] , c);
                pq.push(make_pair(-dis[st][v] , v));
            }
        }
    }
}

int main(void)
{
    int n , m , t;
    scanf("%d %d %d",&n , &m , &t);
    for(int i=0;i<=304;i++){
        for(int j=0;j<=304;j++){
            dis[i][j] = 1e18;
        }
    }
    for(int i=0;i<m;i++){
        ll in1 , in2 , in3;
        scanf("%lld %lld %lld",&in1 , &in2 , &in3);
        edges[in1].push_back(make_pair(in2 , in3));
        //edges[in2].push_back(make_pair(in1 , in3));
    }
    for(int i=1;i<=n;i++)Dijkstra(i);
    while(t--){
        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        ll d = dis[in1][in2];
        if(d>1e17)d = -1;
        printf("%lld\n",d);
    }
    return 0;
}
