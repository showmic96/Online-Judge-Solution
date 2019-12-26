// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e5+9;
ll dp1[MAX+9] , dp2[MAX+9] , sum[MAX+9] , cost[MAX+9];
vector<int>edges[MAX+9];

void dfs1(int u , int par = -1)
{
    sum[u] = cost[u];
    dp1[u] = 0;

    for(auto v:edges[u]){

        if(v!=par){

            dfs1(v , u);
            sum[u]+=sum[v];
            dp1[u]+=sum[v]+dp1[v];
        }
    }
}

void dfs2(int u , int par = -1 , ll sum1 = 0 , ll sum2 = 0)
{
    sum2+=sum1;
    dp2[u] = dp1[u] + sum2;
    for(auto v : edges[u]){
        if(v!=par)
            dfs2(v , u , sum1+sum[u]-sum[v] , sum2+dp1[u]-dp1[v]-sum[v]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++)cin >> cost[i];
    for(int i=0;i<n-1;i++){

        int in1 , in2;
        cin >> in1 >> in2;
        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }

    dfs1(1);
    dfs2(1);

    ll ans = 0;

    for(int i=1;i<=n;i++)ans = max(ans , dp2[i]);
    cout << ans << endl;

    return 0;
}
