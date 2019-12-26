// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 555;

typedef long long ll;

ll INF = 123456789;

ll cost[MAX];
ll ans[MAX];

vector< pair<ll , ll > >edges[MAX];

void setUp()
{
    for(int i=0;i<555;i++){
        edges[i].clear();
        cost[i] = INF;
        ans[i] = 0;
    }
}

void Dijkstra(int i)
{
    priority_queue < pair < ll , ll > > current;
    current.push(make_pair(0 , i));
    cost[i] = 0;
    //cout << cost[i] << endl;
    while(!current.empty()){

        ll c = -current.top().first , u = current.top().second;

        current.pop();

        //if(c>cost[u])continue;

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            ll v = edges[u][i].first;
            ll c2 = edges[u][i].second;
            //cout << cost[u] << " " << cost[v]+c2 << endl;
            if(cost[v]>cost[u]&&cost[v]>c2){

                cost[v]=max(cost[u],c2);

                ans[v] = max(ans[v] , max(cost[u] , c2));

                current.push(make_pair(-cost[v] , v));

            }
        }
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        setUp();
        //memset(cost , INF , sizeof(cost));

        ll n , m;
        cin >> n >> m;

        while(m--){

            ll u , v , c;
            scanf("%lld %lld %lld",&u , &v , &c);
            edges[u].push_back(make_pair(v , c));
            edges[v].push_back(make_pair(u , c));
        }

        int in;

        scanf("%d",&in);

        Dijkstra(in);

        printf("Case %d:\n",i+1);

        for(int j=0;j<n;j++){

            if(cost[j]==INF)printf("Impossible\n");
            else printf("%lld\n",cost[j]);
        }
    }
    return 0;
}
