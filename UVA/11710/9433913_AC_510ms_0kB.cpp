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

        ans+=v[i].w;

        Union(v[i].u , v[i].v);
    }

    int counter = 0;

    for(int i=1;i<=n;i++)if(parent[i]==i){counter++;}

    if(counter>1)printf("Impossible\n");
    else printf("%.0f\n",ans);
}

int main(void)
{

    while(scanf("%d %d", &n , &m)==2){

        if(!n&&!m)break;

        v.clear();
        map<string , int>mp;

        for(int i=0;i<=n;i++)parent[i] = i;

        for(int i=1;i<=n;i++){

            string ar;
            cin >> ar;
            mp[ar] = i;
        }

        for(int i=0;i<m;i++){

            string in1 , in2;
            double in3;

            cin >> in1 >> in2;
            scanf("%lf",&in3);
            int t1 = mp[in1] , t2 = mp[in2];
            v.push_back(node(t1 , t2 , in3));
        }

        string ar;
        cin >> ar;

        sort(v.begin() , v.end() , cmp);

        Kruskal();
    }

    return 0;
}
