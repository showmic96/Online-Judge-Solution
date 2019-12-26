// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 3e5+9;
ll dp[MAX+9] , cost[MAX+9] , ans = 0;
vector<pair<ll , ll > > edges[MAX+9];

int n;

void dfs(int u , int par = -1)
{
    dp[u] = cost[u];
    vector<ll>current;

    for(auto it : edges[u]){

        ll v = it.first;
        ll c = it.second;
        if(v==par)continue;
        dfs(v , u);

        ll temp = dp[v] - c + cost[u];
        current.push_back(max(0LL , temp));
        dp[u] = max(dp[u] , temp);
    }

    sort(current.rbegin() , current.rend());
    ans = max(ans , dp[u]);
    if(current.size()==1)ans = max(ans , current[0]);
    if(current.size()>=2)ans = max(ans , current[0]+current[1]-cost[u]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++)cin >> cost[i];
    for(int i=0;i<n-1;i++){

        ll in1 , in2 , in3;
        cin >> in1 >> in2 >> in3;
        edges[in1].push_back(make_pair(in2 , in3));
        edges[in2].push_back(make_pair(in1 , in3));
    }

    memset(dp , 0 , sizeof(dp));
    dfs(1);
    cout << ans << endl;

    return 0;
}
