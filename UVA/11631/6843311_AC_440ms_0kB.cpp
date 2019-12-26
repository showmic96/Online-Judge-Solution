#include<bits/stdc++.h>
using namespace std;

struct Edge{

    int u , v , w;
};

bool ope(Edge A , Edge B){

    return A.w < B.w ;
}

Edge edge[200001];
int parent[200001];
int level[200001];

int Find(int x)
{
    if(parent[x]==x)return x;

    return parent[x] = Find(parent[x]);
}

void Union(int x , int y)
{
    parent[x] = y;
}

int kruskal(int sz)
{
    sort(edge ,edge+sz , ope);

    //int sz = edge.size();

    int ans = 0;

    for(int i=0;i<sz;i++){

        int p = Find(edge[i].u) , q = Find(edge[i].v);

        if(p!=q){

            if(level[p]>level[q])swap(p,q);
            level[q]+=level[p];
            Union(p,q);
            //cout << ans << endl;
            ans+=edge[i].w;
        }
    }
    return ans;
}

int main(void)
{
    int a , b;

    while(cin >> a >> b){

        if(!a&&!b)break;

        //for(int i=1;i<=a;i++)parent[i]=i;

        int total = 0 , in1 , in2 ,in3;

        for(int i=0;i<b;i++){
            parent[i]=i;
            level[i]=1;
            cin >> in1 >> in2 >> in3;
            //cout << "YeS";
            edge[i].u=in1;
            edge[i].v=in2;
            edge[i].w=in3;
            total+=in3;
            //cout << "YES";
        }

        cout << total - kruskal(b) << endl;
    }
    return 0;
}
