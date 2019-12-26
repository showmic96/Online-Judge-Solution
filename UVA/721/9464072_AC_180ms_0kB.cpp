// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000000+9;
const ll INF = 1234567891011121314;

vector<pair<ll , ll > > edges[MAX] , rEdges[MAX];

ll dis1[MAX] , dis2[MAX];


ll bfs1(int n)
{
    queue<ll>current;

    current.push(1);

    dis1[1] = 0;

    while(!current.empty()){

        int u = current.front();
        current.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            int v = edges[u][i].first;
            int c = edges[u][i].second;

            if(dis1[v]>dis1[u]+c){

                dis1[v] = dis1[u]+c;
                current.push(v);
            }
        }
    }

    ll temp = 0;

    for(int i=1;i<=n;i++)temp+=dis1[i];

    return temp;
}

ll bfs2(int n)
{
    queue<ll>current;

    current.push(1);

    dis2[1] = 0;

    while(!current.empty()){

        int u = current.front();
        current.pop();

        int si = rEdges[u].size();

        for(int i=0;i<si;i++){

            int v = rEdges[u][i].first;
            int c = rEdges[u][i].second;

            if(dis2[v]>dis2[u]+c){

                dis2[v] = dis2[u]+c;
                current.push(v);
            }
        }
    }

    ll temp = 0;

    for(int i=1;i<=n;i++)temp+=dis2[i];

    return temp;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n , m;
        scanf("%d %d",&n , &m);

        for(int i=0;i<=n;i++){

            edges[i].clear();
            rEdges[i].clear();
            dis1[i] = INF;
            dis2[i] = INF;
        }

        while(m--){

            ll in1 , in2 , in3;
            scanf("%lld %lld %lld",&in1 , &in2 , &in3);

            edges[in1].push_back(make_pair(in2 , in3));
            rEdges[in2].push_back(make_pair(in1 , in3));
        }

        ll ans1 = bfs1(n);
        ll ans2 = bfs2(n);

        printf("%lld\n",ans1+ans2);
    }

    return 0;
}
