// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 110;

vector<int>edges[MAX+9];
int ar[MAX][4];

void dfs(int i , int l)
{
    if(l!=-1){

        if(ar[i][l]!=0)return ;
        ar[i][l] = 1;
    }

    int si = edges[i].size();

    for(int j=0;j<si;j++){

        if(l==0)dfs(edges[i][j] , 1);
        else dfs(edges[i][j] , 0);
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , m;
        scanf("%d %d",&n , &m);

        memset(ar , 0 , sizeof(ar));
        for(int i=0;i<=n;i++)edges[i].clear();

        while(m--){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            edges[in1].push_back(in2);
            edges[in2].push_back(in1);
        }

        dfs(1 , -1);

        int ans = 0;

        for(int i=1;i<=n;i++){

            if(ar[i][1]==1)ans++;
        }

        printf("Case %d: %d\n",++c , ans);
    }
    return 0;
}
