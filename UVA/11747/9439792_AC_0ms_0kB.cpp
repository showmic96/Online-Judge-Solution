// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node{

    ll u , v , w;

    node(ll ut , ll vt , ll wt){

        u = ut;
        v = vt;
        w = wt;
    }
};

bool cmp(node A , node B)
{
    return A.w < B.w;
}

ll n , m;
vector<ll>ans;
vector<node>v;
ll parent[1234567];

int Find(int x)
{
    if(x==parent[x])return x;
    return Find(parent[x]);
}

void Union(int x , int y)
{
    int px = Find(x);
    int py = Find(y);

    parent[py] = px;
}

void Kruskal()
{
    int si = v.size();

    for(int i=0;i<=n;i++)parent[i] = i;

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))ans.push_back(v[i].w);

        else{

            Union(v[i].u , v[i].v);
        }
    }

}

int main(void)
{

    while(scanf("%lld %lld",&n , &m)==2){

        if(!n&&!m)break;

        v.clear();
        ans.clear();

        while(m--){

            ll in1 , in2 , in3;
            scanf("%lld %lld %lld",&in1 , &in2 , &in3);

            v.push_back(node(in1 , in2 , in3));
        }

        sort(v.begin() , v.end() , cmp);

        Kruskal();

        int si = ans.size();

        if(si==0)printf("forest");

        for(int i=0;i<si;i++){

            if(i!=0)printf(" ");
            printf("%lld",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
