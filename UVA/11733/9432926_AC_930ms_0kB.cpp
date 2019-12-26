// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct node{

    int u , v;
    double w;

    node(int ut , int vt , double wt){

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
int parent[123456];
int n , m , a;

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
    double ans = 0;
    int si = v.size();

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))continue;
        if(v[i].w>=a)continue;

        ans+=v[i].w;

        Union(v[i].u , v[i].v);
    }

    int counter = 0;

    for(int i=1;i<=n;i++)if(parent[i]==i){counter++;ans+=a;}

    printf("%.0f %d\n",ans,counter);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    bool space = false;

    while(t--){

        v.clear();

        scanf("%d %d %d", &n , &m , &a);

        for(int i=0;i<=n;i++)parent[i] = i;

        for(int i=0;i<m;i++){

            int in1 , in2;
            double in3;

            scanf("%d %d %lf",&in1 , &in2 , &in3);

            v.push_back(node(in1 , in2 , in3));
        }

        sort(v.begin() , v.end() , cmp);

        printf("Case #%d: ",++c);

        Kruskal();
    }

    return 0;
}
