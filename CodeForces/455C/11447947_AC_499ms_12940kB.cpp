// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 3e5 + 9;

vector<int>edges[MAX+9];
int parent[MAX+9];
int diameter[MAX+9];
bool visited[MAX+9];
int level[MAX+9];

int Find(int x)
{
    if(parent[x]==x)return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x , int y)
{
    int px = Find(x);
    int py = Find(y);

    parent[py] = px;
}

void pre()
{
    memset(visited , false , sizeof(visited));
    memset(level , 0 , sizeof(level));
    memset(diameter , 0 , sizeof(diameter));

    for(int i=0;i<=MAX;i++)parent[i] = i;
}

int bfs2(int u)
{
    queue<int>current;
    current.push(u);
    level[u] = 1;

    int last = 1;

    while(!current.empty()){

        u = current.front();
        current.pop();

        last = level[u];

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            if(level[edges[u][i]]==0){

                level[edges[u][i]] = level[u]+1;
                current.push(edges[u][i]);
            }
        }
    }

    return last;
}

void bfs(int u)
{
    queue<int>current;
    current.push(u);

    visited[u] = true;

    while(!current.empty()){

        u = current.front();
        current.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            if(visited[edges[u][i]]==false){

                visited[edges[u][i]] = true;
                current.push(edges[u][i]);
            }
        }
    }

    int ans = bfs2(u);

    diameter[Find(u)] = ans-1;

}

int main(void)
{
    pre();

    int n , m , q;
    scanf("%d %d %d",&n, &m, &q);

    for(int i=0;i<m;i++){

        int in1 , in2;
        scanf("%d %d",&in1, &in2);

        Union(in1 , in2);

        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    for(int i=1;i<=n;i++){

        if(visited[i]==false){

            bfs(i);
        }
    }

    for(int i=0;i<q;i++){

        int in;
        scanf("%d",&in);

        if(in==1){

            int in1;
            scanf("%d",&in1);

            printf("%d\n",diameter[Find(in1)]);
        }

        else{

            int in1 , in2;
            scanf("%d %d",&in1, &in2);

            if(Find(in1)!=Find(in2)){

                int px = Find(in1);
                int py = Find(in2);

                parent[py] = px;

                diameter[px] = max((double)diameter[py], max((double)diameter[px] , (double)(ceil(1.00*diameter[px]/2.00) + ceil(1.00*diameter[py]/2.00) + 1)));
            }
        }
    }

    return 0;
}
