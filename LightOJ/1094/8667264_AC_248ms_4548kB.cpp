// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 30000+9;
int dis[MAX];
int value;

vector<pair<int , int> >edges[MAX];

int Dijkstra(int in)
{
    value = 0;
    queue<pair<int , int> > current;

    current.push(make_pair(in , 0));

    int ans;

    while(!current.empty()){


        int u = current.front().first;
        int c = current.front().second;
        //cout << u << " " << c << endl;
        current.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            int v = edges[u][i].first;
            int c2 = edges[u][i].second;
            //if(dis[v]!=0)continue;
            //cout << v << " DEBUG " << u << endl;
            if(v==in)continue;
            if(dis[v]==0){

                dis[v] = dis[u] + c2;
                //cout << dis[v] << " " << v << endl;
                current.push(make_pair(v , dis[v]));

                if(dis[v]>value){

                    value = dis[v];
                    ans = v;
                }
            }
        }
    }

    return ans;
}

void setUp2(int n)
{
    for(int i=0;i<=n;i++)dis[i] = 0;
}

void setUp(int n)
{
    for(int i=0;i<=n;i++)edges[i].clear();
}

int main(void)
{

    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){

        int n;
        scanf("%d",&n);
        setUp(n);

        for(int j=0;j<n-1;j++){

            int in1 , in2 , in3;

            scanf("%d %d %d",&in1 , &in2 , &in3);

            edges[in1].push_back(make_pair(in2 , in3));
            edges[in2].push_back(make_pair(in1 , in3));
        }
        //cout << edges[0][0].second << endl;
        value = 0;

        setUp2(n);//memset(dis , 0 , sizeof(dis));

        int v = Dijkstra(0);
        //cout << v << endl;
        value = 0;
        setUp2(n);

        Dijkstra(v);
        //cout << v << endl;
        printf("Case %d: %d\n",i+1 , value);
    }

    return 0;
}
