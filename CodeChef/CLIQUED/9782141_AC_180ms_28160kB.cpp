// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1234567891011121314;

vector<pair<int ,int> > edges[100005];

ll dis[100005];

void Dijkstra(int s)
{
    priority_queue<pair<ll , ll > > pq;

    pq.push(make_pair(0 , s));

    dis[s] = 0;

    while(!pq.empty()){

        ll u = pq.top().second;
        ll c = -pq.top().first;

        pq.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            ll v = edges[u][i].first;
            ll c = edges[u][i].second;

            if(dis[v]>dis[u]+c){

                dis[v] = dis[u]+c;

                pq.push(make_pair(-dis[v] , v));
            }
        }
    }
}

void Dijkstra2(priority_queue< pair < ll , ll > > pq)
{

    while(!pq.empty()){

        ll u = pq.top().second;
        ll c = -pq.top().first;

        pq.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            ll v = edges[u][i].first;
            ll c = edges[u][i].second;

            if(dis[v]>dis[u]+c){

                dis[v] = dis[u]+c;

                pq.push(make_pair(-dis[v] , v));
            }
        }
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n , k , x , m , s;
        scanf("%d %d %d %d %d",&n , &k , &x , &m , &s);

        for(int i=0;i<=n;i++){

            edges[i].clear();
            dis[i] = INF;
        }

        while(m--){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);

            edges[in1].push_back(make_pair(in2 , in3));
            edges[in2].push_back(make_pair(in1 , in3));
        }

        Dijkstra(s);

        ll mi = INF;
        priority_queue<pair < ll ,ll > > pq;

        for(int i=1;i<=k;i++){

            mi = min(mi , dis[i]);
        }

        for(int i=1;i<=k;i++){

            dis[i] = min(dis[i] , mi+x);
            pq.push(make_pair(-dis[i] , i));
        }

        Dijkstra2(pq);

        for(int i=1;i<=n;i++){

            if(i!=1)printf(" ");
            printf("%lld",dis[i]);
        }

        printf("\n");
    }
    return 0;
}
