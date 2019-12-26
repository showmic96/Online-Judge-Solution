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

int parent[1234567];
vector<node>v;
vector<int>ans;

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

void Kruskal(int n , int j)
{
    int si = v.size() , temp = 0 , counter = 0;

    bool check = false;
    for(int i=0;i<=n;i++)parent[i] = i;
    for(int i=0;i<si;i++){

        if(i==j)continue;

        if(Find(v[i].u)==Find(v[i].v)){

            continue;
        }

        Union(v[i].u , v[i].v);
        temp+=v[i].w;
        counter++;
    }

    if(counter==n-1)ans.push_back(temp);
}

int main(void)
{
    int t ;
    scanf("%d",&t);

    while(t--){

        v.clear();
        ans.clear();
        int n , m;
        scanf("%d %d",&n , &m);

        for(int i=0;i<=n;i++)parent[i] = i;

        while(m--){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);

            v.push_back(node(in1 , in2 , in3));
        }

        sort(v.begin() , v.end() , cmp);

        int si = v.size() , counter = 0;
        bool inMST [si+9];
        memset(inMST , false , sizeof(inMST));

        for(int i=0;i<si;i++){

            if(Find(v[i].u)==Find(v[i].v)){

                continue;
            }

            Union(v[i].u , v[i].v);
            inMST[i] = true;
            counter+=v[i].w;
        }

        for(int i=0;i<si;i++){

            if(inMST[i]==true)Kruskal(n , i);
        }


        sort(ans.begin(), ans.end());
        printf("%d %d\n",counter , ans[0]);

    }

    return 0;
}
