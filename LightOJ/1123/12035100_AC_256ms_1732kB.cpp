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

bool operator<(edge A , edge B)
{
    return A.w < B.w;
}

vector<edge> v , temp;

int parent[10005];

int Find(int x)
{
    if(x==parent[x])return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x , int y)
{
    int px = Find(x);
    int py = Find(y);

    parent[py] = px;
}

ll Kruskal(int n)
{
    sort(v.begin() , v.end());

    int si = v.size();
    int counter = 0;
    ll ans = 0;

    for(int i=0;i<=n;i++)parent[i] = i;

    temp.clear();

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))continue;

        Union(v[i].u , v[i].v);

        counter++;
        temp.push_back(v[i]);
        ans+=v[i].w;
    }

    v.clear();
    v = temp;
    if(counter!=n-1)return -1;

    return ans;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , m;
        scanf("%d %d",&n , &m);

        v.clear();

        printf("Case %d:\n",++c);

        while(m--){

            ll in1 , in2 , in3;
            scanf("%lld %lld %lld",&in1 , &in2, &in3);
            v.push_back(edge(in1, in2 , in3));

            printf("%lld\n",Kruskal(n));
        }
    }
    return 0;
}
