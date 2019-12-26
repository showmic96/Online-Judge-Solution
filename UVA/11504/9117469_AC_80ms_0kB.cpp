// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 123456;

vector<int>edges[MAX+9] , node;
bool isVisited[MAX+9];

void setUp()
{
    node.clear();
    for(int i=0;i<MAX;i++){

        edges[i].clear();
        isVisited[i] = false;
    }
}

void dfs1(int u)
{

    if(isVisited[u]==true)return;
    isVisited[u] = true;

    int si =  edges[u].size();

    for(int i=0;i<si;i++){

        dfs1(edges[u][i]);
    }

    node.push_back(u);
}

void dfs2(int u)
{

    if(isVisited[u]==true)return;
    isVisited[u] = true;

    int si =  edges[u].size();

    for(int i=0;i<si;i++){

        dfs2(edges[u][i]);
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        setUp();

        int n , m;
        scanf("%d %d",&n , &m);

        while(m--){

            int in1 ,in2;
            scanf("%d %d",&in1 , &in2);

            edges[in1].push_back(in2);
        }

        for(int i=1;i<=n;i++){

            if(isVisited[i]==false){

                dfs1(i);
            }
        }

        int ans = 0;
        int si = node.size();

        memset(isVisited , false , sizeof(isVisited));
        reverse(node.begin() , node.end());

        for(int i=0;i<si;i++){

            if(isVisited[node[i]]==false){

                ans++;
                dfs2(node[i]);
            }
        }

        printf("%d\n",ans);

    }
    return 0;
}
