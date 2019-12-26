// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1000+9;
int parent[MAX+9];

struct node{

    ll u , v , w;
    node(ll _u , ll _v , ll _w){

        u = _u;
        v = _v;
        w = _w;
    }
};

bool operator<(node A , node B)
{
    return A.w<B.w;
}

vector<node>v;

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

void Kruskal(ll x)
{
    int si = v.size();
    ll ans = 0;

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))continue;

        Union(v[i].u , v[i].v);
        ans+=v[i].w;
    }

    printf("%lld\n",ans*x);

    v.clear();
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll p , n , m;
        scanf("%lld %lld %lld",&p , &n , &m);

        for(int i=0;i<m;i++){

            ll in1 , in2 , in3;
            scanf("%lld %lld %lld",&in1 , &in2 , &in3);
            v.push_back(node(in1 , in2 , in3));
        }

        sort(v.begin() , v.end());

        for(int i=0;i<=n;i++)parent[i] = i;

        Kruskal(p);
    }
    return 0;
}
