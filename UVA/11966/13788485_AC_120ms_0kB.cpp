// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool vis[1005];
vector<pair<int , double> > edges[1005];
vector<pair<double, double > > v;
int n;double d;

double dis(double x1 , double y1 , double x2 , double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void dfs(int u)
{
    if(vis[u])return ;
    vis[u] = true;

    int si = edges[u].size();

    for(int i=0;i<si;i++){

        if(edges[u][i].second<=d)dfs(edges[u][i].first);
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        memset(vis , false , sizeof(vis));

        scanf("%d %lf",&n , &d);

        for(int i=0;i<=n;i++)edges[i].clear();

        v.clear();
        for(int i=0;i<n;i++){

            double in1 , in2;
            scanf("%lf %lf",&in1 , &in2);
            v.push_back(make_pair(in1 , in2));
        }

        int counter = 0;

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                double di = dis(v[i].first , v[i].second , v[j].first , v[j].second);
                edges[i].push_back(make_pair(j , di));
                edges[j].push_back(make_pair(i , di));
            }
        }

        for(int i=0;i<n;i++){

            if(vis[i]==false){

                dfs(i);
                counter++;
            }
        }

        printf("Case %d: %d\n",++c , counter);
    }

    return 0;
}
