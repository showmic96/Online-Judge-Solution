// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct node{

    int u , v , w;

    node(int ut , int vt , int wt){

        u = ut;
        v = vt;
        w = wt;
    }
};

vector<node>v;
int dis[123456];

int main(void)
{
    int t;
    scanf("%d",&t);

    while(t--){

        int n , m;
        scanf("%d %d",&n , &m);
        v.clear();

        while(m--){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 ,&in2 , &in3);

            v.push_back(node(in1 , in2 , in3));
        }

        for(int i=0;i<=n;i++)dis[i] = INF;

        for(int i=0;i<n-1;i++){

            int si = v.size();

            for(int j=0;j<si;j++){

                if(dis[v[j].v]>dis[v[j].u]+v[j].w){

                    dis[v[j].v] = dis[v[j].u] + v[j].w;
                }
            }
        }

        int si = v.size();

        for(int i=0;i<si;i++){

            if(dis[v[i].v]>dis[v[i].u]+v[i].w){

                si = -1;
                break;
            }
        }

        if(si==-1)printf("possible\n");
        else printf("not possible\n");
    }
    return 0;
}
