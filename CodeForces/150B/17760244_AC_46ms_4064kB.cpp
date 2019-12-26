// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int MAX = 2005;

vector<int>edges[MAX+9];
ll n , m , k;
bool taken[MAX] , ar[MAX][MAX] , vis[MAX];

void dfs(int u)
{
    if(vis[u]==true)return ;
    vis[u] = true;

    for(int i=0;i<n;i++){

        if(i==u)continue;
        if(ar[u][i]==true)dfs(i);
    }
}

int main(void)
{
    memset(taken , false , sizeof(taken));
    memset(vis , false , sizeof(vis));

    scanf("%lld %lld %lld",&n , &m , &k);
    for(int i=0;i<n;i++){

        for(int j=0;j<k&&i+j<n&&i+k-j-1<n;j++){

            ar[i+j][i+k-j-1] = 1;
            ar[i+k-j-1][i+j] = 1;
        }
    }
    ll ans = 1LL;
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            ans*=m;
            ans%=MOD;
            dfs(i);
        }
    }
    printf("%lld\n",ans);

    return 0;
}
