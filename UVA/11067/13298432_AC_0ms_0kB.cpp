// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[105][105];
bool vis[105][105];
int n , m;

ll f(int i , int j)
{
    if(i>n||j>m)return 0;
    if(i<0||j<0)return 0;
    if(i==n&&j==m)return 1;

    if(vis[i][j])return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    ll value = 0;
    value+=f(i+1 , j);
    value+=f(i , j+1);

    return dp[i][j] = value;
}

int main(void)
{
    while(scanf("%d %d",&n , &m)==2){

        if(!n&&!m)break;
        memset(dp , -1 , sizeof(dp));
        memset(vis , false , sizeof(vis));

        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            vis[in1][in2] = true;
        }

        ll ans = f(0 , 0);

        if(ans==0)printf("There is no path.\n");
        else if(ans==1)printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
        else printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n",ans);
    }
    return 0;
}
