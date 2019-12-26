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

        if(visited[p1]==true&&visited[p2]==true)continue;

        if(visited[p1]+visited[p2]==1){

            Union(p1 , p2);
            visited[p1] = true;
            visited[p2] = true;

            ans+=w;
        }

        else{

            Union(p1 , p2);
            ans+=w;
        }
    }

    return ans;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        reset();

        int n;
        scanf("%d",&n);

        scanf("%s",&x);
        string ar(x);

        vector<int>data;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            data.push_back(in);
        }

        for(int i=0;i<n-1;i++){

            v.push_back(edge(i , i+1 , data[i+1]-data[i]));
        }

        for(int i=0;i<n;i++){

            if(ar[i]=='1')visited[i] = true;
        }

        ll ans = Kruskal(n);

        printf("%lld\n",ans);
    }

    return 0;
}
