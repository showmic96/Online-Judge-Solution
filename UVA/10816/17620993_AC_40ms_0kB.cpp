// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100+9;
const double INF = 1e18;

struct s{

    ll v;
    double r , d;
    s(ll _v , double _r , double _d){

        v = _v;
        r = _r;
        d = _d;
    }
};

vector<s>edges[MAX];
vector<int>v;
int n , m , par[MAX];
double dis[MAX];

void Dijkstra(int st , double lim)
{
    priority_queue<pair<double , ll > > pq;
    for(int i=0;i<=n;i++){

        dis[i] = INF;
        par[i] = i;
    }
    dis[st] = 0;
    pq.push({0 , st});
    while(!pq.empty()){

        ll u = pq.top().second;
        double c = -pq.top().first;
        pq.pop();

        for(auto it : edges[u]){

            ll v = it.v;
            double r = it.r;
            double d = it.d;

            if(r>lim)continue;

            if(dis[v]>dis[u]+d){

                dis[v] = dis[u]+d;
                pq.push({-dis[v] , v});
                par[v] = u;
            }
        }
    }
}

void print(int x)
{
    v.push_back(x);
    if(x==par[x])return ;
    print(par[x]);
}

int main(void)
{
    while(scanf("%d %d",&n , &m)==2){

        for(int i=0;i<=n;i++)edges[i].clear();
        int st , en;
        scanf("%d %d",&st , &en);

        for(int i=0;i<m;i++){

            ll in1 , in2;
            double in3 , in4;
            scanf("%lld %lld %lf %lf",&in1 , &in2 , &in3 , &in4);
            edges[in1].push_back(s(in2 , in3 , in4));
            edges[in2].push_back(s(in1 , in3 , in4));
        }

        int t = 50;
        double hi = 100 , low = 0 , mid , ans = -1;
        while(t--){

            mid = (hi+low)/2;
            Dijkstra(st , mid);

            if(dis[en]!=INF){

                ans = mid;
                hi = mid;
            }
            else{

                low = mid;
            }
        }

        Dijkstra(st , ans);

        v.clear();
        print(en);
        for(int i=0;i<v.size();i++){

            if(i)printf(" ");
            printf("%d",v[v.size()-1-i]);
        }
        printf("\n");
        printf("%.1f %.1f\n",dis[en] , ans);
    }

    return 0;
}
