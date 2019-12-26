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

bool cmp(node A , node B)
{
    return A.w < B.w;
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
    int si = v.size();
    int ans2 = 0;

    for(int i=0;i<=si;i++)parent[i] = i;

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))continue;

        ans2+=v[i].w;
        Union(v[i].u , v[i].v);

    }

    printf("%d\n",ans2);
}

int main(void)
{
    int n , m , k;
    bool space = false;

    while(scanf("%d",&n)==1){

        if(space)printf("\n");space = true;

        int ans1 = 0;

        for(int i=0;i<n-1;i++){

            int in1 , in2 , in3;

            scanf("%d %d %d",&in1 , &in2 , &in3);

            ans1+=in3;
        }

        v.clear();

        scanf("%d",&k);

        while(k--){

            int in1 , in2 , in3;

            scanf("%d %d %d",&in1 , &in2 , &in3);

            v.push_back(node(in1 , in2 , in3));
        }

        scanf("%d",&m);
        while(m--){

            int in1 , in2 , in3;

            scanf("%d %d %d",&in1 , &in2 , &in3);

            v.push_back(node(in1 , in2 , in3));
        }

        sort(v.begin() , v.end() , cmp);

        printf("%d\n",ans1);

        Kruskal();
    }

    return 0;
}
