// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 12345;
int level[MAX+9];
vector<int>edges[MAX+9];

void setUp()
{
    for(int i=0;i<MAX;i++){

        edges[i].clear();
        level[i] = 0;
    }
}

void bfs(int u)
{
    queue<int>current;

    current.push(u);

    while(!current.empty()){

        u = current.front();
        current.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            if(level[edges[u][i]]==0){

                level[edges[u][i]] = level[u] + 1;

                current.push(edges[u][i]);
            }
        }
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    bool space = false;

    while(t--){

        if(space)printf("\n");space = true;

        setUp();

        int n , m;
        scanf("%d %d",&n , &m);

        while(m--){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            edges[in1].push_back(in2);
            edges[in2].push_back(in1);
        }

        bfs(0);

        for(int i=1;i<n;i++){

            if(level[i]==0)printf("-1\n");
            else printf("%d\n",level[i]);
        }
    }
    return 0;
}
