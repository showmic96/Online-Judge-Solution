// Strongly Connected Component.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+9;

vector<int>edges[MAX+9];
vector<int>edgesr[MAX+9];
stack<int>store;
bool visited[MAX+9];

void dfs1(int u)
{
    if(visited[u]==true)return ;

    visited[u] = true;

    int si = edges[u].size();

    for(int i=0;i<si;i++){

        dfs1(edges[u][i]);
    }

    store.push(u);
}

void dfs2(int u)
{
    if(visited[u]==true)return ;

    visited[u] = true;

    int si = edgesr[u].size();

    for(int i=0;i<si;i++){

        dfs2(edgesr[u][i]);
    }

}

int main(void)
{
    //freopen("input.txt","r",stdin);
    int n , m;
    while(cin >> n >> m){

        if(!n&&!m)break;

        for(int i=0;i<=n;i++){

            edges[i].clear();
            edgesr[i].clear();
        }

        while(m--){

            int u , v , w;
            cin >> u >> v >> w;

            if(w==1){
                edges[u].push_back(v);
                edgesr[v].push_back(u);
            }

            else{

                edges[u].push_back(v);
                edgesr[v].push_back(u);
                edges[v].push_back(u);
                edgesr[u].push_back(v);
            }
        }

        memset(visited , false , sizeof(visited));

        for(int i=1;i<=n;i++){

            if(visited[i]==false){

                dfs1(i);
            }
        }

        memset(visited , false , sizeof(visited));

        int counter = 0;

        while(!store.empty()){

            int temp = store.top();
            store.pop();

            if(visited[temp]==false){

                counter++;
                dfs2(temp);
            }
        }

        if(counter!=1)counter = 0;
        cout << counter << endl;
    }

    return 0;
}
