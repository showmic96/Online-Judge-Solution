// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

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
vector<double>ans;

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


void Kruskal()
{
    int si = v.size();

    for(int i=0;i<si;i++){

        if(Find(v[i].u)==Find(v[i].v)){

            continue;
        }

        Union(v[i].u , v[i].v);
        ans.push_back(v[i].w);
    }
}

double dis(pair<double , double> p1 , pair<double , double> p2)
{
    double temp = sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));

    return temp;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ans.clear();
        v.clear();

        int n;
        scanf("%d",&n);

        vector<pair<double , double> > point;

        double in1 , in2;
        int counter = 0;

        while(scanf("%lf",&in1)==1){

            if(in1==-1)break;

            scanf("%lf",&in2);

            point.push_back(make_pair(in1 ,in2));

            counter++;
        }

        for(int i=0;i<counter;i++){

            for(int j=i+1;j<counter;j++){

                v.push_back(node(i , j , dis(point[i] , point[j])));
            }
        }

        for(int i=0;i<=counter;i++)parent[i] = i;

        sort(v.begin() , v.end() , cmp);

        Kruskal();

        printf("%.0f\n",ceil(ans[counter-1-n]));
    }
    return 0;
}
