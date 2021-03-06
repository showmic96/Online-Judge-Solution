// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct point{

    double x , y;

    point(double xt , double yt){

        x = xt;
        y = yt;
    }
};

struct node{

    int u , v;
    double w;

    node(int ut , int vt , double wt){

        u = ut;
        v = vt;
        w = wt;
    }
};

struct mySturct{

    int u , v;

    mySturct(int ut , int vt){

        u = ut;
        v = vt;
    }
};

bool cmp(node A , node B)
{
    return A.w < B.w;
}

vector<point>p;
vector<node>v;
int parent[123456];

double dis(point a , point b)
{
    double dist = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return dist;
}

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
    int si = v.size();

    double ans = 0;

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))continue;

        ans+=v[i].w;

        Union(v[i].u , v[i].v);
    }

    printf("%.2f\n",ans);
}

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        p.clear();
        v.clear();


        for(int i=0;i<=n;i++)parent[i] = i;

        for(int i=0;i<n;i++){

            double in1 , in2;
            scanf("%lf %lf",&in1 , &in2);

            p.push_back(point(in1 , in2));
        }

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                v.push_back(node(i+1 , j+1 , dis(p[i] , p[j])));
            }
        }

        int k;
        scanf("%d",&k);

        for(int i=0;i<k;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            Union(in1 , in2);
        }

        sort(v.begin() , v.end() , cmp);

        Kruskal();
    }

    return 0;
}
