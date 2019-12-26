// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 9;
int level[MAX+9];
bool visited[MAX+9];
vector<pair<int , int > > edges[MAX+9];
queue<int>q;

void bfs(int x)
{
    queue<int>current;
    current.push(x);

    level[x] = 1;

    while(!current.empty()){

        int u = current.front();
        current.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            if(level[edges[u][i].first]==0){

                level[edges[u][i].first] = level[u] + 1;
                current.push(edges[u][i].first);
            }
        }

    }
}

void dfs1(int i)
{
    if(visited[i]==true)return ;
    visited[i] = true;

    int si = edges[i].size();

    for(int j=0;j<si;j++){

        dfs1(edges[i][j].first);
    }

    q.push(i);
}

void dfs2(int i)
{
    if(visited[i]==true)return ;
    visited[i] = true;

    int si = edges[i].size();

    for(int j=0;j<si;j++){

        if(level[i] > level[edges[i][j].first]){

            dfs2(edges[i][j].first);
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i=0;i<n-1;i++){

        int in1 , in2 , in3;
        scanf("%d %d %d" , &in1 , &in2 , &in3);

        edges[in1].push_back(make_pair(in2 , in3));
        edges[in2].push_back(make_pair(in1 , in3));
    }

    memset(level , 0 , sizeof(level));

    bfs(1);

    memset(visited , false , sizeof(visited));

    dfs1(1);

    memset(visited , false , sizeof(visited));

    vector<int>ans;

    while(q.empty()==false){

        if(visited[q.front()]==false){

            int si = edges[q.front()].size();
            bool check = false;

            for(int i=0;i<si;i++){

                if(edges[q.front()][i].second==2){

                    if(level[q.front()]>level[edges[q.front()][i].first]){

                        check = true;
                    }
                }
            }

            if(check==true){

                ans.push_back(q.front());
                dfs2(q.front());
            }
        }

        q.pop();
    }

    int si = ans.size();

    printf("%d\n",si);

    for(int i=0;i<si;i++){

        printf("%d ", ans[i]);

    }

    printf("\n");

    return 0;
}
