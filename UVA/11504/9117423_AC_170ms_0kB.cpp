// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 123456;
vector<int>edges1[MAX+9];
vector<int>edges2[MAX+9];
vector<int>node;
bool isVisited1[MAX+9] , isVisited2[MAX+9];

void setUp()
{
    node.clear();
    for(int i=0;i<MAX;i++){

        edges1[i].clear();
        edges2[i].clear();

        isVisited1[i] = false;
        isVisited2[i] = false;
    }
}

void dfs1(int u)
{
    if(isVisited1[u]==true)return;
    isVisited1[u] = true;

    int si = edges1[u].size();

    for(int i=0;i<si;i++){

        dfs1(edges1[u][i]);
    }

    node.push_back(u);
}

void dfs2(int u)
{
    if(isVisited2[u]==true)return ;
    isVisited2[u] = true;
    int si = edges2[u].size();

    for(int i=0;i<si;i++){

        dfs2(edges2[u][i]);
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){
        setUp();
        int n , m;
        scanf("%d %d",&n ,&m);

        for(int i=0;i<m;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);

            edges1[in1].push_back(in2);
            edges2[in1].push_back(in2);
        }

        for(int i=1;i<=n;i++){

            if(isVisited1[i]==false){

                dfs1(i);

            }
        }

        int ans = 0;
        int si = node.size();
        reverse(node.begin() , node.end());

        for(int i=0;i<si;i++){

            if(isVisited2[node[i]]==false){

                ans++;
                dfs2(node[i]);
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
