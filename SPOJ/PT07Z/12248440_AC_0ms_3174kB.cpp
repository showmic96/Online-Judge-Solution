// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 10000+9;
vector<int>edges[MAX+9];
int level[MAX+9];

int bfs()
{
    queue<int>current;
    current.push(1);

    int ans = 1;

    while(!current.empty()){

        int u = current.front();
        current.pop();

        int si = edges[u].size();

        ans = u;

        for(int i=0;i<si;i++){

            if(level[edges[u][i]]==0){

                level[edges[u][i]] = level[u]+1;
                current.push(edges[u][i]);
            }
        }
    }

    return ans;
}

int bfs2(int u)
{
    memset(level , 0 , sizeof(level));

    queue<int>current;
    current.push(u);

    int ans = 1;

    while(!current.empty()){

        u = current.front();
        current.pop();

        int si = edges[u].size();

        ans = level[u];

        for(int i=0;i<si;i++){

            if(level[edges[u][i]]==0){

                level[edges[u][i]] = level[u]+1;
                current.push(edges[u][i]);
            }
        }
    }

    return ans;
}

int main(void)
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n-1;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    memset(level , 0 , sizeof(level));

    int last = bfs();

    int ans = bfs2(last);

    printf("%d\n",ans);

    return 0;
}
