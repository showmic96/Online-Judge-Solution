// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 123;
vector<int>edges[MAX+9];

bool visited[MAX+9];

int bfs(int u)
{
    queue<int>current;

    current.push(u);
    visited[u] = true;
    int counter = 0;

    while(!current.empty()){

        u = current.front();
        current.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            if(visited[edges[u][i]]==false){

                visited[edges[u][i]] = true;

                current.push(edges[u][i]);
                counter++;
            }
        }
    }

    return counter;
}

int main(void)
{
    int n;
    while(cin >> n){

        if(!n)break;

        for(int i=1;i<=n;i++){

            edges[i].clear();

            int m;
            cin >> m;

            while(m--){

                int in;
                cin >> in;
                edges[i].push_back(in);
            }
        }

        int hi = 0 , ans = 0;

        for(int i=1;i<=n;i++){

            memset(visited , false , sizeof(visited));

            int value = bfs(i);

            if(value>hi){

                hi = value;
                ans = i;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
