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

int f(int x , int y)
{
    if(x<y)swap(x , y);
    int xt = x , yt = y;
    int counter = 0;

    while(x!=0){

        int t1 = x%10;
        int t2 = y%10;

        if(t1<t2)swap(t1 , t2);

        counter+=min(t1-t2 , 10-t1+t2);

        x/=10;
        y/=10;
    }

    return counter;
}

void Kruskal(int ans)
{
    int si = v.size();

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))continue;

        Union(v[i].u , v[i].v);

        ans+=v[i].w;
    }

    printf("%d\n",ans);
}

int main(void)
{

    int t;
    scanf("%d",&t);
    while(t--){

        v.clear();

        int n;
        scanf("%d",&n);

        vector<int>data;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            data.push_back(in);

            parent[i] = i;
        }

        parent[n] = n;

        int ans = 123456789;

        for(int i=0;i<n;i++){

            ans = min(ans , f(0 , data[i]));

            for(int j=i+1;j<n;j++){

                int temp = f(data[i] , data[j]);

                v.push_back(node(i , j , temp));
            }
        }

        sort(v.begin() , v.end() , cmp);

        Kruskal(ans);
    }
    return 0;
}
