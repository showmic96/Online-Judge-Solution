// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 50000+9;

vector<int>edges[MAX+9] , ans;
bool visited[MAX+9];
int parent[MAX+9];
int parent2[MAX+9];

void init()
{
    for(int i=0;i<=MAX;i++){

        edges[i].clear();
        parent[i] = i;
        parent2[i] = 123456789;
    }
}

int en;

void bfs(int x)
{
    memset(visited , false , sizeof(visited));
    queue<int>current;

    current.push(x);
    visited[x] = true;

    vector<int>v;

    while(true){

        int u = current.front();
        if(u==en)break;
        current.pop();

        int si = edges[u].size();


        for(int i=0;i<si;i++){

            if(visited[edges[u][i]]==false){

                visited[edges[u][i]] = true;
                v.push_back(edges[u][i]);

                parent[edges[u][i]] = u;
            }
        }

        if(v.size()!=0){

            int si = v.size();

            sort(v.begin() , v.end());

            for(int i=0;i<si;i++)current.push(v[i]);
            v.clear();
        }
    }
}

void path(int x)
{
    if(x==parent[x]){

        return ;
    }
    ans.push_back(x);

    path(parent[x]);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        vector<int>v;
        ans.clear();

        init();

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        for(int i=1;i<n;i++){

            edges[v[i]].push_back(v[i-1]);
            edges[v[i-1]].push_back(v[i]);
        }

        edges[v[0]].push_back(v[1]);
        edges[v[1]].push_back(v[0]);

        en = v[n-1];

        bfs(v[0]);

        printf("Case %d:\n",++c);
        path(en);

        int si = ans.size();

        printf("%d",v[0]);

        for(int i=si-1;i>=0;i--){

            printf(" %d",ans[i]);
        }

        printf("\n");
    }
    return 0;
}
