// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

vector<pair<int , int> > edges[1234];
int dis[1234];
const int INF = 1234567;

void Dijkstra(int st)
{
    priority_queue<pair<int , int> > pq;

    dis[st] = 0;

    pq.push(make_pair(0 , st));

    while(!pq.empty()){

        int u = pq.top().second;
        int c1 = -pq.top().first;

        pq.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            int v = edges[u][i].first;
            int c = edges[u][i].second;

            if(dis[v]>dis[u]+c){

                dis[v] = dis[u] + c;

                pq.push(make_pair(-dis[v] , v));
            }
        }
    }
}

void setUp()
{
    for(int i=0;i<123;i++)dis[i] = 12345678;
}

int main(void)
{
    //setUp();
    int n, e , t , m;
    scanf("%d %d %d %d",&n , &e , &t , &m);
    while(m--){

        int in1 , in2 , in3;
        scanf("%d %d %d",&in1 , &in2 , &in3);
        edges[in1].push_back(make_pair(in2, in3));
    }

    //Dijkstra(e);
    int counter = 0;
    for(int i=1;i<=n;i++){

        setUp();
        Dijkstra(i);
        if(dis[e]<=t)counter++;
    }

    printf("%d\n",counter);

    return 0;
}
