// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int INF = 123456789;

struct myStruct{

    int c , u , b;

    myStruct(int ct , int ut , int bt){

        c = ct;
        u = ut;
        b = bt;
    }

    bool operator <(const myStruct & u)const{
        return c > u.c;
    }
};

vector<pair<int , int> > edges[505];
int dis[505][2];

void Dijkstra()
{
    priority_queue<myStruct>pq;

    pq.push(myStruct(0 , 0 , 0));

    dis[0][0] = 0;

    while(!pq.empty()){

        int u = pq.top().u;
        int c1 = pq.top().c;
        int b = pq.top().b;

        pq.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            int v = edges[u][i].first;
            int c = edges[u][i].second;

            if(b==0){

                if(dis[v][1]>dis[u][0]+c){

                    dis[v][1] = dis[u][0]+c;
                    pq.push(myStruct(dis[v][1] , v , 1));
                }
            }

            else{

                if(dis[v][0]>dis[u][1]+c){

                    dis[v][0] = dis[u][1]+c;
                    pq.push(myStruct(dis[v][0] , v , 0));
                }
            }
        }
    }
}

int main(void)
{
    int n , m , c = 0;

    while(scanf("%d %d",&n , &m)==2){

        for(int i=0;i<=n;i++){

            edges[i].clear();
            dis[i][0] = INF;
            dis[i][1] = INF;
        }

        while(m--){

            int in1 ,in2 , in3;

            scanf("%d %d %d",&in1 , &in2 , &in3);

            edges[in1].push_back(make_pair(in2 , in3));
            edges[in2].push_back(make_pair(in1 , in3));
        }

        Dijkstra();

        printf("Set #%d\n",++c);
        if(dis[n-1][0]==INF)printf("?\n");
        else printf("%d\n",dis[n-1][0]);
    }

    return 0;
}
