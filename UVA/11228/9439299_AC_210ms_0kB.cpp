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

    double u , v , w;

    node(double ut , double vt , double wt){

        u = ut;
        v = vt;
        w = wt;
    }
};

bool cmp(node A , node B)
{
    return A.w < B.w;
}

int n , r;
vector<point>p;
vector<node>v;
int parent[1234567];

double dis(point p1 , point p2)
{
    double dist = sqrt((p1.x - p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));

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

    for(int i=0;i<=si;i++)parent[i] = i;

    double ans1=0 , ans2=0;
    int counter = 0;

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v))continue;

        Union(v[i].u , v[i].v);

        if(v[i].w<=r){

            ans1+=v[i].w;
            counter++;
        }

        else{

            ans2+=v[i].w;
        }
    }

    printf("%d %.0f %.0f\n",n-counter , ans1 , ans2);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        v.clear();
        p.clear();

        scanf("%d %d",&n , &r);

        for(int i=0;i<n;i++){

            double in1 , in2;
            scanf("%lf %lf",&in1 , &in2);
            p.push_back(point(in1 , in2));
        }

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                double w = dis(p[i] , p[j]);
                v.push_back(node(i , j , w));
            }
        }

        sort(v.begin() , v.end() , cmp);

        printf("Case #%d: ",++c);
        Kruskal();
    }
    return 0;
}
