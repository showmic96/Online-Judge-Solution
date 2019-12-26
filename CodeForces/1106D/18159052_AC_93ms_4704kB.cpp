// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>edges[100005];
bool vis[100005];

void Dijkstra()
{
    memset(vis , false , sizeof(vis));

    vis[1]=true;
    priority_queue<int>pq;
    pq.push(-1);
    while(!pq.empty()){

        int u = -pq.top();
        pq.pop();
        printf("%d ",u);

        for(auto v : edges[u]){

            if(vis[v]==false){

                vis[v] = true;
                pq.push(-v);
            }
        }
    }
}

int main(void)
{
    int n , m;

    scanf("%d %d",&n , &m);
    for(int i=0;i<m;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    Dijkstra();

    return 0;
}
