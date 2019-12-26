// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>edges[1005];
bool vis[1005];

double dis(double x1, double y1 , double x2 , double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool cmp(pair<double , int> A , pair<double , int> B)
{
    return A.first < B.first;
}

void dfs(int u)
{
    if(vis[u])return ;
    vis[u] = true;

    for(int i=0;i<edges[u].size();i++)dfs(edges[u][i]);
}

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(!n)break;
        vector<pair<int , int> > point;

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            point.push_back(make_pair(in1 , in2));

            edges[i].clear();
        }

        for(int i=0;i<n;i++){

            vector<pair<double , int> >now;

            for(int j=0;j<n;j++){

                if(i==j)continue;

                double d = dis(point[i].first , point[i].second , point[j].first , point[j].second);

                if(now.size()<2)now.push_back(make_pair(d,j));
                else{

                    sort(now.begin() ,now.end() , cmp);
                    if(d<now[1].first){

                        now[1].first = d;
                        now[1].second = j;
                    }
                }
            }

            edges[i].push_back(now[0].second);
            edges[i].push_back(now[1].second);
        }

        memset(vis , false , sizeof(vis));
        bool check = true;
        dfs(0);

        for(int i=0;i<n;i++)if(vis[i]==false)check = false;

        if(check)printf("All stations are reachable.\n");
        else printf("There are stations that are unreachable.\n");
    }
    return 0;
}
