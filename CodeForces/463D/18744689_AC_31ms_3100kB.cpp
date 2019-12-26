// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e3+9;
vector<int>edges[MAX];
bool vis[MAX];
int v[6][MAX] , dp[MAX];

int f(int u)
{
    if(dp[u]!=-1)return dp[u];
    int ans = 1;
    for(auto v : edges[u]){
        ans = max(ans , f(v)+1);
    }
    return dp[u] = ans;
}

int main(void)
{
    int n , k;
    scanf("%d %d",&n , &k);
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            int in;
            scanf("%d",&in);
            v[i][in] = j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            bool found = false;
            for(int l=0;l<k;l++){
                if(v[l][i]>=v[l][j]){
                    found = true;
                }
            }
            if(found==false)edges[i].push_back(j);
        }
    }
    memset(dp , -1 , sizeof(dp));
    memset(vis , false , sizeof(vis));
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans , f(i));
    }
    printf("%d\n",ans);
    return 0;
}
