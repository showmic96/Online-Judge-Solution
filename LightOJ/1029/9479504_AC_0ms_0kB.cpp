// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct node{

    int u , v , w;

    node(int ut , int vt , int wt)
    {
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
    return parent[x] = Find(parent[x]);
}

void Union(int x , int y)
{
    int px = Find(x);
    int py = Find(y);

    parent[py] = px;
}

int Kruskal()
{
    int si = v.size() , ans = 0;

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))continue;

        Union(v[i].u , v[i].v);
        ans+=v[i].w;
    }

    return ans;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);

        int in1 , in2 , in3;

        while(scanf("%d %d %d",&in1 , &in2 , &in3)==3){

            if(!in1&&!in2&&!in3)break;
            v.push_back(node(in1 , in2 , in3));
        }

        sort(v.begin() , v.end() , cmp);

        for(int i=0;i<=n;i++)parent[i] = i;

        int ans = Kruskal();

        reverse(v.begin() , v.end());

        for(int i=0;i<=n;i++)parent[i] = i;

        ans+=Kruskal();

        printf("Case %d: ",++c);

        if(ans%2==1)printf("%d/2\n",ans);
        else printf("%d\n",ans/2);

        v.clear();
    }
    return 0;
}
