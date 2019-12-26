// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 10005;
const ll INF = 123456778912131452;

ll dis[10005][11];

vector<pair< pair < ll , ll > , ll > > edges[MAX];
ll n , m , k , d;

void Dijkstra(int n)
{
    priority_queue<pair < pair<ll , ll > , ll > , vector<pair< pair < ll , ll> , ll> > , greater<pair < pair<ll , ll > , ll> > > pq;

    pq.push(make_pair(make_pair(0 , 0) , 0));

    dis[0][0] = 0;

    while(!pq.empty()){

        int c1 = pq.top().first.first;
        int x = pq.top().first.second;
        int u = pq.top().second;

        pq.pop();

        //if(dis[u][x]<c1)continue;

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            int v = edges[u][i].first.first;
            int c = edges[u][i].first.second;
            int y = edges[u][i].second;

            if(x+y>d)continue;
            //cout << y << endl;

            if(dis[v][x+y]>dis[u][x]+c){

                dis[v][x+y] = dis[u][x]+c;

                pq.push(make_pair(make_pair(dis[v][x+y] , x+y) , v));
            }
        }
    }

    ll ans = INF;

    for(int i=0;i<=d;i++){

        ans = min(dis[n-1][i] , ans);
        //cout << dis[n-1][i] << endl;
    }

    if(ans==INF)printf("Impossible\n");
    else printf("%lld\n",ans);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%lld %lld %lld %lld",&n , &m , &k , &d);

        for(int i=0;i<=n;i++){

            edges[i].clear();

            for(int j=0;j<=d;j++){

                dis[i][j] = INF;
            }
        }

        while(m--){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);
            edges[in1].push_back(make_pair(make_pair(in2 , in3) , 0));
        }

        while(k--){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);
            edges[in1].push_back(make_pair(make_pair(in2 , in3) , 1));
        }

        printf("Case %d: ",++c);

        Dijkstra(n);
    }
    return 0;
}
