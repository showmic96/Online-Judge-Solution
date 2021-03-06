// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 3e5+9;

vector<pair<ll , ll > > edges[MAX];
ll dp[MAX] , temp[MAX];

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);
    for(int i=0;i<m;i++){

        ll in1 , in2 , in3;
        scanf("%lld %lld %lld",&in1 , &in2 , &in3);
        edges[in3].push_back(make_pair(in1 , in2));
    }
    for(int i=0;i<MAX;i++){

        int si = edges[i].size();
        for(int j=0;j<si;j++){

            temp[edges[i][j].second] = 0;
        }
        for(int j=0;j<si;j++){

            temp[edges[i][j].second] = max(temp[edges[i][j].second] , dp[edges[i][j].first]+1);
        }
        for(int j=0;j<si;j++){

            dp[edges[i][j].second] = max(dp[edges[i][j].second] , temp[edges[i][j].second]);
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++)ans = max(ans , dp[i]);
    printf("%lld\n",ans);

    return 0;
}
