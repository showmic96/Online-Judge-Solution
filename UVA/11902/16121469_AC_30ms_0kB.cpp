// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>edges[105];
int ans[105][105];
bool vis[105];

void dfs(int u , int no)
{
    if(u==no)return ;
    if(vis[u]==true)return ;
    vis[u] = true;

    for(int i=0;i<edges[u].size();i++)dfs(edges[u][i] , no);
}

void dfs2(int u)
{
    if(vis[u]==true)return ;
    vis[u] = true;
    for(int i=0;i<edges[u].size();i++)dfs2(edges[u][i]);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)edges[i].clear();

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                int in;
                scanf("%d",&in);
                if(in==1)edges[i].push_back(j);
            }
        }

        memset(ans , 0 , sizeof(ans));

        for(int i=0;i<n;i++){

            memset(vis , false , sizeof(vis));
            dfs(0 , i);

            for(int j=0;j<n;j++){

                if(vis[j]==false)ans[i][j]=1;
            }
        }

        memset(vis , false , sizeof(vis));
        dfs2(0);

        printf("Case %d:\n",++c);
        printf("+");
        for(int i=0;i<2*n-1;i++)printf("-");
        printf("+\n");

        for(int i1=0;i1<n;i1++){

            printf("|");
            for(int j1=0;j1<n;j1++){

                if(vis[j1]==false)printf("N|");
                else if(ans[i1][j1]==true)printf("Y|");
                else printf("N|");
            }

            printf("\n");
            printf("+");
            for(int i=0;i<2*n-1;i++)printf("-");
            printf("+\n");
        }
    }
    return 0;
}
