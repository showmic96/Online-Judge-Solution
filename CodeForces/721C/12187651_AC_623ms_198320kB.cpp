// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

struct node{

    int u , c , t;
    node(int _u , int _c , int _t){

        u = _u;
        c = _c;
        t = _t;
    }

    bool operator<(node d) const {
      return t == d.t ? c < d.c : t > d.t;
   }
};

int n , m ,t;
vector<pair<int , int> >edges[5005];
int par[5005][5005];
int dis[5005][5005];

void bfs()
{
    priority_queue<node>current;
    current.push(node(1 , 1 , 0));
    dis[1][1] = 0;
    while(!current.empty()){

        int u = current.top().u;
        int c = current.top().c;
        int tt = current.top().t;
        current.pop();
        if(u==n)continue;
        int si = edges[u].size();

        for(int i=0;i<si;i++){

            int v = edges[u][i].first;
            int w = edges[u][i].second;

            if(tt+w>t)continue;

            if(dis[v][c+1]==-1||dis[v][c+1]>dis[u][c]+w){

                dis[v][c+1] = dis[u][c]+w;
                par[v][c+1] = u;

                current.push(node(v , c+1 , dis[v][c+1]));
            }
        }
    }
}

int main(void)
{
    memset(par , -1 , sizeof(par));
    memset(dis , -1 , sizeof(dis));

    scanf("%d %d %d",&n , &m , &t);

    while(m--){

        int in1 , in2 , in3;
        scanf("%d %d %d",&in1 , &in2 , &in3);
        edges[in1].push_back(make_pair(in2 , in3));
    }

    bfs();

    vector<int>v;

    for(int i=5000;i>=1;i--){

        if(par[n][i]==-1)continue;
        int temp = n;

        while(temp!=1){

            v.push_back(temp);
            temp = par[temp][i];
            i--;
        }

        v.push_back(1);
        reverse(v.begin(),v.end());

        int si = v.size();
        printf("%d\n",si);
        for(int j=0;j<si;j++){

            if(j>0)printf(" ");
            printf("%d",v[j]);
        }
        printf("\n");
        break;
    }

    return 0;
}