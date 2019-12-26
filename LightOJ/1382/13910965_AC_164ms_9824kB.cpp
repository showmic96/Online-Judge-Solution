// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1000000007;

const int MAX = 1000+9;
ll dp[MAX+9] , ncr[MAX+9][MAX+9];
int par[MAX+9] , child[MAX+9];
vector<int>edges[MAX+9];

int dfs(int u)
{
    child[u] = 1;

    for(int i=0;i<edges[u].size();i++){

        child[u]+=dfs(edges[u][i]);
    }
    return child[u];
}

ll c(int n , int k)
{
    if(k==1)return n;
    if(k==0)return 1;
    if(n==k)return 1;

    if(ncr[n][k]!=-1)return ncr[n][k];
    return ncr[n][k] = ((c(n-1 , k)%MOD)+(c(n-1 , k-1)%MOD))%MOD;
}

ll f(int u)
{
    if(dp[u]!=-1)return dp[u];

    int t = child[u] - 1;

    ll value = 1;

    for(int i=0;i<edges[u].size();i++){

        value*=c(t , child[edges[u][i]]);
        value%=MOD;
        value*=f(edges[u][i]);
        value%=MOD;

        t-=child[edges[u][i]];
    }

    return dp[u] = value;
}

int main(void)
{
    memset(ncr , -1 , sizeof(ncr));

    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(child , 0 , sizeof(child));

        int n;
        scanf("%d",&n);

        for(int i=0;i<=n;i++){
            par[i] = -1;
            edges[i].clear();
        }

        for(int i=0;i<n-1;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            edges[in1].push_back(in2);
            par[in2] = in1;
        }

        int st = -1;

        for(int i=1;i<=n;i++){

            if(par[i]==-1)st = i;
        }

        dfs(st);

        memset(dp , -1 , sizeof(dp));

        printf("Case %d: %lld\n",++c , f(st));
    }
    return 0;
}
