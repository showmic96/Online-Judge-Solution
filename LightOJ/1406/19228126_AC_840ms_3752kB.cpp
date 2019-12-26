// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[(1<<16) + 5];
int n , m , mask_temp;
bool visited[17][(1<<16)+10];
bool taken[(1<<16)+10];
vector<int>edges[17];

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

void dfs(int i , int mask)
{
    if(visited[i][mask]==true)return ;
    visited[i][mask] = true;
    taken[mask] = true;
    int si = edges[i].size();
    for(int j=0;j<si;j++){
        dfs(edges[i][j] , Set(mask , edges[i][j]));
    }
}

ll f(int mask)
{
    if(mask==0)return 0;
    if(dp[mask]!=-1)return dp[mask];
    ll value = 1e9;
    for(int j=mask;j>0;j=(mask&(j-1))){
        if(taken[j]==true)value = min(value , f(mask^j) + 1);
    }
    return dp[mask] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        memset(dp , -1 , sizeof(dp));
        memset(visited , false , sizeof(visited));
        memset(taken , false ,sizeof(taken));
        scanf("%d %d",&n , &m);
        for(int i=0;i<n;i++)edges[i].clear();
        while(m--){
            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            in1--;in2--;
            edges[in1].push_back(in2);
        }
        for(int i=0;i<n;i++)dfs(i , Set(0 , i));
        printf("Case %d: %lld\n",++c , f((1<<n)-1));
    }
    return 0;
}
