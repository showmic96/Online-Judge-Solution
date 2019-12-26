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
    return A.w > B.w;
}

vector<node>v;
int parent[123456];

int Find(int x)
{
    if(x==parent[x])return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x ,int y)
{
    int px = Find(x);
    int py = Find(y);

    parent[py] = px;
}


void Kruskal()
{
    int si = v.size() , ans = 0;

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v)){

            ans+=v[i].w;
            continue;
        }

        Union(v[i].u , v[i].v);
    }

    printf("%d\n",ans);
}

int main(void)
{

    int t;
    while(scanf("%d",&t)==1){

        if(!t)break;

        int n , m;
        while(t--){

            scanf("%d %d",&n,&m);

            v.clear();


            vector<int>data;

            for(int i=0;i<m;i++){

                int in1 , in2 , in3;
                scanf("%d %d %d",&in1 , &in2 , &in3);
                v.push_back(node(in1 ,in2 , in3));
            }

            for(int i=0;i<=n;i++){

                parent[i] = i;
            }

            sort(v.begin() , v.end() , cmp);

            Kruskal();

        }
    }

    return 0;
}
