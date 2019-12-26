// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 123;
vector<pair<int , int> > edges[MAX];
int dis[MAX];

void setUp(int n)
{
    for(int i=0;i<=n;i++){

        edges[i].clear();
        dis[i] = 1234567;
    }
}

void Dijkstra()
{
    priority_queue<pair < int , int > > pq;

    pq.push(make_pair(1 , 0));
    dis[1] = 0;

    while(!pq.empty()){

        int u = pq.top().first;
        int c1 = pq.top().second;

        pq.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            int v = edges[u][i].first;
            int c2 = edges[u][i].second;

            if(dis[v]>dis[u]+c2){

                dis[v] = dis[u] + c2;
                pq.push(make_pair(v , -dis[v]));
            }
        }
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        int n , m;
        cin >> n >> m;

        setUp(n);

        while(m--){

            int in1 ,in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);

            edges[in1].push_back(make_pair(in2 , in3));
            edges[in2].push_back(make_pair(in1 , in3));
        }

        Dijkstra();

        if(dis[n]!=1234567)printf("Case %d: %d\n",i+1 , dis[n]);
        else printf("Case %d: Impossible\n",i+1);
    }
    return 0;
}
