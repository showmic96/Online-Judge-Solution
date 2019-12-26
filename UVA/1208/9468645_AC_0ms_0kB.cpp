// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

struct node{

    int u , v , w;

    node(int ut , int vt , int wt){

        if(ut>vt)swap(ut , vt);

        u = ut;
        v = vt;
        w = wt;
    }
};

bool cmp(node A , node B)
{
    return A.w < B.w;
}

bool cmp2(node A , node B)
{
    if(A.w!=B.w)return A.w < B.w;
    if(A.u!=B.u)return A.u < B.u;
    return A.v < B.v;
}

int parent[1234567];
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

void Kruskal()
{
    int si = v.size();
    vector<node>ans;

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))continue;

        Union(v[i].u , v[i].v);

        ans.push_back(node(v[i].u , v[i].v , v[i].w));
    }

    sort(ans.begin() , ans.end() ,cmp2);

    si = ans.size();

    for(int i=0;i<si;i++){

        printf("%c-%c %d\n",'A'+ans[i].u , 'A'+ans[i].v , ans[i].w);
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        v.clear();

        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            parent[i] = i;

            for(int j=0;j<n;j++){

                int in;
                scanf("%d,",&in);
                if(in)v.push_back(node(i , j , in));
            }
        }

        sort(v.begin() , v.end() ,cmp);

        printf("Case %d:\n",++c);
        Kruskal();
    }
    return 0;
}
