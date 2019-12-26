// In the name of Allah the Most Merciful.

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
vector<int>edges[100005];
vector<int>ans;

ll dis[100005];
ll INF = 1234567891011121314;
bool visited[100005];

void dfs(int i)
{
    if(visited[i]==true)return;
    visited[i] = true;

    ans.push_back(i);

    int si = edges[i].size();

    for(int j=0;j<si;j++){

        dfs(edges[i][j]);
    }

    return ;
}

int main(void)
{
    int c = 0 , t ;
    scanf("%d", &t);

    while(t--){

        v.clear();

        int n , m;
        scanf("%d %d", &n , &m);

        for(int i=0;i<=n;i++){

            edges[i].clear();
            dis[i] = INF;
            visited[i] = false;
        }

        for(int i=0;i<m;i++){

            ll in1 , in2 , in3;
            scanf("%lld %lld %lld", &in1 , &in2 , &in3);

            v.push_back(edge(in2 , in1 , in3));

            edges[in2].push_back(in1);
            if(i==0)dis[in1] = 0;
        }


        for(int i=0;i<n-1;i++){

            int si = v.size();

            for(int j=0;j<si;j++){

                if(dis[v[j].v]>dis[v[j].u]+v[j].w){

                    dis[v[j].v] = dis[v[j].u]+v[j].w;
                }
            }
        }

        vector<int>store;

        int si = v.size();

        for(int j=0;j<si;j++){

            if(dis[v[j].v]>dis[v[j].u]+v[j].w){

                store.push_back(v[j].u);
                dis[v[j].v] = dis[v[j].u]+v[j].w;
            }
        }

        ans.clear();
        si = store.size();

        for(int i = 0 ;i<si;i++){

            if(visited[store[i]]==false){

                dfs(store[i]);
            }
        }

        sort(ans.begin() , ans.end());

        si = ans.size();

        printf("Case %d:",++c);

        for(int i=0;i<si;i++){

            printf(" %d", ans[i]);
        }

        if(si==0)printf(" impossible");

        printf("\n");
    }

    return 0;
}
