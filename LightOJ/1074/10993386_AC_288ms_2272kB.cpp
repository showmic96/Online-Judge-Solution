// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge{

    ll u , v , w;

    edge(ll _u , ll _v , ll _w){

        u = _u;
        v = _v;
        w = _w;
    }
};

vector<edge>v;
ll dis[202];
ll INF = 1234567891011121314;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);
        vector<ll>cost;
        v.clear();

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);

            cost.push_back(in);
            dis[i+1] = INF;
        }

        int m;
        scanf("%d",&m);

        for(int i=0;i<m;i++){

            ll in1 , in2;
            scanf("%lld %lld", &in1 ,&in2);

            v.push_back(edge(in1 , in2 , ((cost[in2-1] - cost[in1-1])*(cost[in2-1] - cost[in1-1])*(cost[in2-1] - cost[in1-1]))));
        }

        dis[1] = 0;

        for(int i=0;i<n+1000;i++){


            int si = v.size();

            for(int j=0;j<si;j++){


                if(dis[v[j].v]>dis[v[j].u]+v[j].w){

                    dis[v[j].v] = dis[v[j].u] + v[j].w;
                }
            }
        }
        
        ll inf = 1234567891011;
        
        int q;
        scanf("%d", &q);
        
        printf("Case %d:\n", ++c );

        while(q--){

            ll in;
            scanf("%lld", &in);

            if(dis[in]>=3&&dis[in]<inf)printf("%lld\n" , dis[in]);
            else printf("?\n");
        }
    }

    return 0;
}
