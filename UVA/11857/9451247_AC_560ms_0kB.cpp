// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct node{

    int u , v , w;

    node(int ut , int vt , int wt){

        u = ut;
        v = vt;
        w = wt;
    }
};

bool cmp(node A ,node B)
{
    return A.w < B.w;
}

vector<node>v;
int parent[1234567];

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

void Kruskal(int n)
{
    sort(v.begin() , v.end() , cmp);

    int si = v.size() , ans , counter = 0;

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))continue;

        ans = v[i].w;

        Union(v[i].u , v[i].v);

        counter++;
    }

    if(counter==n-1)printf("%d\n",ans);
    else printf("IMPOSSIBLE\n");
}

int main(void)
{
    int n , m;

    while(scanf("%d %d",&n , &m)==2){

        if(!n&&!m)break;

        v.clear();

        while(m--){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);
            v.push_back(node(in1 , in2 , in3));
        }

        for(int i=0;i<=n;i++)parent[i] = i;

        Kruskal(n);
    }

    return 0;
}
