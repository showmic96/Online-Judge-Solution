// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+9;

vector<int>edges[MAX+9];
vector<int>v;
bool visited[MAX+9];
int counter;

void dfs(int u)
{
    if(visited[u]==true)return ;
    visited[u] = true;

    counter+=v[u];

    int si = edges[u].size();

    for(int i=0;i<si;i++){

        dfs(edges[u][i]);
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n , m;
        scanf("%d %d",&n, &m);

        for(int i=0;i<=n;i++){

            edges[i].clear();
        }

        v.clear();

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        for(int i=0;i<m;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            edges[in1].push_back(in2);
            edges[in2].push_back(in1);
        }

        memset(visited , false , sizeof(visited));
        bool check = true;

        for(int i=0;i<n;i++){

            if(visited[i]==false){

                counter = 0;

                dfs(i);

                if(counter!=0)check = false;
            }
        }

        if(check==true)printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
