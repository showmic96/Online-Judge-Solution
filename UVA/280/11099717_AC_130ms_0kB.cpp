// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 110;

vector<int>edges[MAX+9];

bool visited[MAX+9];

void reset()
{
    for(int i=0;i<MAX;i++){

        edges[i].clear();
    }
}

void dfs(int i , int st)
{
    if(visited[i]==true)return ;
    if(i!=st)visited[i] = true;

    int si = edges[i].size();

    for(int j=0;j<si;j++){

        dfs(edges[i][j] , -1);
    }
}

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(n==0)break;

        reset();

        int lim;
        while(scanf("%d",&lim)==1){

            if(lim==0)break;

            int v;

            while(scanf("%d",&v)==1){

                if(v==0)break;

                edges[lim].push_back(v);
            }
        }

        int q;
        scanf("%d",&q);

        while(q--){

            int st;
            scanf("%d",&st);

            memset(visited , false , sizeof(visited));

            dfs(st , st);

            vector<int>ans;

            for(int i=1;i<=n;i++){

                if(visited[i]==false)ans.push_back(i);
            }

            printf("%d", ans.size());

            int si = ans.size();

            for(int i=0;i<si;i++){

                printf(" %d",ans[i]);
            }

            printf("\n");
        }
    }
    return 0;
}
