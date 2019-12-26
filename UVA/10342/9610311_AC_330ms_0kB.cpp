// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node{

    ll u , c;
    node(ll ct , ll ut){

        u = ut;
        c = ct;
    }
};

bool operator < (node A , node B)
{
    return A.c > B.c;
}

vector<node>edges[50005];
vector<ll>dis[50005];

void Dijkstra(ll st)
{
    priority_queue<node>pq;

    pq.push(node(0 , st));

    while(!pq.empty()){

        ll c = pq.top().c;
        ll u = pq.top().u;

        pq.pop();

        if(dis[u].size()==0)dis[u].push_back(c);
        else if(dis[u].back()!=c)dis[u].push_back(c);

        if(dis[u].size()>3)continue;

        ll si = edges[u].size();

        for(int i=0;i<si;i++){

            ll v = edges[u][i].u;
            ll cc = edges[u][i].c;

            if(dis[v].size()==2)continue;

            ll temp = c+cc;

            pq.push(node(temp , v));

        }
    }
}

int main(void)
{
    int t , c = 0;

    ll n , m;

    while(scanf("%lld %lld",&n , &m)==2){

        for(int i=0;i<=n;i++){

            edges[i].clear();
        }

        while(m--){

            ll in1 , in2 , in3;
            scanf("%lld %lld %lld",&in1 , &in2 , &in3);

            edges[in1].push_back(node(in3 , in2));
            edges[in2].push_back(node(in3 , in1));
        }

        int q;
        scanf("%d",&q);

        printf("Set #%d\n",++c );

        while(q--){

            ll in1 , in2;
            scanf("%lld %lld",&in1 , &in2);

            for(int i=0;i<=n;i++)dis[i].clear();

            Dijkstra(in1);

            if(dis[in2].size()<2)printf("?\n");
            else printf("%lld\n",dis[in2][1]);
        }
    }
    return 0;
}
