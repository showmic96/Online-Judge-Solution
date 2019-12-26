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
    int a;
    cin >> a;
    map<string,int>maping;
    string ar , br;
    int print = 0;
    while(a--){
        int b , c;
        if(print)cout << endl;
        print=1;

        cin >> b >> c;

        int d = 1, e , i=0;
        maping.clear();

        while(c--){

            cin >> ar >> br >> e;

            if(!maping[ar]){maping[ar]=d;parent[d]=d;level[d]=1;d++;}
            if(!maping[br]){maping[br]=d;parent[d]=d;level[d]=1;d++;}

            edge[i].u = maping[ar];
            edge[i].v = maping[br];
            edge[i].w = e;

            i++;
        }

        cout << kruskal(i) << endl;
    }
    return 0;
}
