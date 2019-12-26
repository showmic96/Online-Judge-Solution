// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 2*1e5+9;
vector<int>edges[MAX+9];
int level1[MAX+9];
int level2[MAX+9];
int mx = 0;

void bfs1(int u)
{
    queue<int>current;
    current.push(u);
    level1[u] = 1;
    while(!current.empty()){

        u = current.front();
        current.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            if(level1[edges[u][i]]==0){

                level1[edges[u][i]] = level1[u] + 1;
                current.push(edges[u][i]);
            }
        }
    }
}


void bfs2(int u)
{
    queue<int>current;
    current.push(u);
    level2[u] = 1;
    while(!current.empty()){

        u = current.front();
        current.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            if(level2[edges[u][i]]==0){
//cout << level1[edges[u][i]] << " " << level2[u]+1 << endl;
                if(level1[edges[u][i]]<=level2[u]+1)continue;
//cout << "yes" << endl;
                level2[edges[u][i]] = level2[u] + 1;
                //mx = max(level2[u]+1 , mx);
                current.push(edges[u][i]);
                //cout << edges[u][i] << endl;
            }
        }
    }
}

int main(void)
{
    int n , x;
    scanf("%d %d",&n, &x);
    int n_temp = n-1;

    while(n_temp--){

        int u , v;
        scanf("%d %d",&u , &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    memset(level1 , 0 , sizeof(level1));
    memset(level2 , 0 , sizeof(level2));

    bfs1(1);
    bfs2(x);

    for(int i=1;i<=n;i++){

        if(level2[i]!=0){

            mx = max(mx , level1[i]);
        }
    }

    printf("%d\n",(mx-1)*2);

    return 0;
}
