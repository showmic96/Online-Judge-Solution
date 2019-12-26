// In the name of Allah the Lord of the Worlds.

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

bool operator < (node A , node B)
{
    return A.w < B.w;
}

vector<node>v;

int parent[55];

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

void Kruskal(int n , int t)
{
    for(int i=0;i<n;i++)parent[i] = i;

    int si = v.size();

    int ans = 0 , counter = 0;

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))continue;

        ans+=v[i].w;
        Union(v[i].u , v[i].v);
        counter++;
    }

    if(counter==n-1){

        printf("%d\n",t-ans);
    }

    else{

        printf("-1\n");
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
        int counter = 0;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                int in;
                scanf("%d",&in);
                if(in==0)continue;
                v.push_back(node(i , j , in));
                counter+=in;
            }
        }

        sort(v.begin() , v.end());
        //cout << counter << endl;
        printf("Case %d: ",++c);
        Kruskal(n , counter);
    }
    return 0;
}
