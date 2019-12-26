// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct node{

    int u , c;
    node(int ct , int ut){

        u = ut;
        c = ct;
    }
};

bool operator < (node A , node B)
{
    return A.c > B.c;
}

vector<node>edges[5005];
vector<int>dis[5005];

void Dijkstra()
{
    priority_queue<node>pq;

    pq.push(node(0 , 1));

    while(!pq.empty()){

        int c = pq.top().c;
        int u = pq.top().u;

        pq.pop();

        if(dis[u].size()==0)dis[u].push_back(c);
        else if(dis[u].back()!=c)dis[u].push_back(c);

        if(dis[u].size()>3)continue;

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            int v = edges[u][i].u;
            int cc = edges[u][i].c;

            if(dis[v].size()==2)continue;

            int temp = c+cc;

            pq.push(node(temp , v));
        }
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , m;
        scanf("%d %d",&n , &m);

        for(int i=0;i<=n;i++){

            edges[i].clear();
            dis[i].clear();
        }

        while(m--){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);

            edges[in1].push_back(node(in3 , in2));
            edges[in2].push_back(node(in3 , in1));
        }

        Dijkstra();

        printf("Case %d: %d\n",++c , dis[n][1]);
    }
    return 0;
}
