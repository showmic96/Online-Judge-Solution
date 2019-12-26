// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 9;
int INF = 1e9;

vector<pair<int , int> > edges[MAX+9];
int dis[MAX+9];

void Dijkstra()
{
    priority_queue<pair<int , int> > pq;

    pq.push(make_pair(0 , 1));

    dis[1] = 0;

    while(!pq.empty()){

        int c = -pq.top().first;
        int u = pq.top().second;

        pq.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            int v = edges[u][i].first;
            int c1 = edges[u][i].second;

            if(dis[u]+c1<dis[v]){

                dis[v] = dis[u] + c1;

                pq.push(make_pair(-dis[v] , v));
            }
        }
    }
}

int main(void)
{
    int n , m;
    scanf("%d %d",&n, &m);

    while(m--){

        int in1, in2;

        scanf("%d %d",&in1 ,&in2);
        edges[in1].push_back(make_pair(in2 , 0));
        edges[in2].push_back(make_pair(in1 , 1));
    }

    for(int i=0;i<=n;i++){

        dis[i] = INF;
    }

    Dijkstra();

    int ans = dis[n];

    if(ans>1e6)printf("-1\n");
    else printf("%d\n",ans);

    return 0;
}
