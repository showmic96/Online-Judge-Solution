// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 30000+9;
const ll INF = 1234567891011121314;

vector<pair<int , int > > edges[MAX+9];

ll dis[2][MAX+9];

void setUp()
{
    for(int i=0;i<=MAX;i++)edges[i].clear();
}

void setUp2()
{
    for(int i=0;i<2;i++){

        for(int j=0;j<=MAX;j++)dis[i][j] = INF;
    }
}

int Dijkstra(int st , int i)
{
    int ans , mx = 0;
    priority_queue<pair<int , int> > current;

    current.push(make_pair(st , 0));

    dis[i][st] = 0;

    while(!current.empty()){

        int u = current.top().first;
        int c1 = -current.top().second;

        current.pop();

        int si = edges[u].size();

        for(int j=0;j<si;j++){

            int v = edges[u][j].first;
            int c2 = edges[u][j].second;

            if(dis[i][v]>dis[i][u]+c2){

                dis[i][v] = dis[i][u] + (ll)c2;
                current.push(make_pair(v , -dis[i][v]));

                if(dis[i][v]>mx){

                    mx = dis[i][v];
                    ans = v;
                }
            }
        }
    }

    return ans;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        setUp();
        int n;
        scanf("%d",&n);

        for(int j=0;j<n-1;j++){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2 , &in3);
            edges[in1].push_back(make_pair(in2 , in3));
            edges[in2].push_back(make_pair(in1 , in3));
        }

        setUp2();

        int t1 = Dijkstra(0 , 0);

        setUp2();

        int t2 = Dijkstra(t1 , 0);

        t1 = Dijkstra(t2 , 1);
        //cout << t1 << " " << t2 << endl;
        printf("Case %d:\n",i+1);

        for(int j=0;j<n;j++){

            printf("%lld\n",max(dis[0][j],dis[1][j]));
        }
    }

    return 0;
}
