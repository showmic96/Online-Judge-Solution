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
    return A.w > B.w;
}

vector<node>v;
int parent[1234567];

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
    sort(v.begin() , v.end() , cmp);

    int si = v.size() , ans;

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))continue;

        ans = v[i].w;

        Union(v[i].u , v[i].v);
    }

    printf("%d\n",ans);
}

int main(void)
{

    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        v.clear();
        int n , m;
        scanf("%d %d",&n , &m);

        while(m--){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);
            v.push_back(node(in1 , in2 , in3));
        }

        for(int i=0;i<=n;i++)parent[i] = i;

        printf("Case #%d: ",++c);

        Kruskal();
    }

    return 0;
}
