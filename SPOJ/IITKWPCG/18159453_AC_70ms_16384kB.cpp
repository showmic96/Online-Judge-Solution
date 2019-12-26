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

bool operator<(edge A , edge B)
{
    return A.w<B.w;
}

const int MAX = 1e5 + 9;
int parent[MAX+9];
bool visited[MAX+9];
char x[MAX+9];

vector<edge>v;

void reset()
{
    for(int i=0;i<=MAX;i++){

        visited[i] = false;
        parent[i] = i;
    }

    v.clear();
}

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

    ll ans = 0;

    int si = v.size();

    for(int i=0;i<si;i++){


        ll u1 = v[i].u;
        ll u2 = v[i].v;
        ll w = v[i].w;

        ll p1 = Find(u1);
        ll p2 = Find(u2);

        if(p1==p2)continue;
        ans+=w;
        Union(p1 , p2);
    }
    ans++;
    return ans;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        reset();

        int n , m;
        scanf("%d %d",&n , &m);

        for(int i=0;i<m;i++){

            ll in1 , in2 , in3 , c = 0;
            scanf("%lld %lld %lld",&in1 , &in2 , &in3);
            while(in3%2LL==0){
                c++;
                in3/=2LL;
            }
            v.push_back(edge(in1 , in2 , c));
        }

        ll ans = Kruskal(n);

        printf("%lld\n",ans);
    }

    return 0;
}
