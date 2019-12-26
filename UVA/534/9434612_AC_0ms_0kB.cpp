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
    double ans = 0;
    int si = v.size();

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))continue;

        ans=v[i].w;

        Union(v[i].u , v[i].v);
        
        if(Find(0)==Find(1))break;
    }

    printf("Frog Distance = %.3f\n",ans);
}

int main(void)
{
    int n , c = 0;

    while(scanf("%d",&n)==1){

        if(!n)break;

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

                v.push_back(node(i , j , dis(p[i] , p[j])));
            }
        }

        printf("Scenario #%d\n",++c);

        sort(v.begin() , v.end() , cmp);

        Kruskal();

        printf("\n");
    }

    return 0;
}
