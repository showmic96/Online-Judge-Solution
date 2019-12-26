// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;
int dp[2][MAX];

int main(void)
{
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &x:v)cin >> x;
    dp[0][0] = dp[1][n-1] = 1;
    for(int i=1;i<n;i++){
        dp[0][i] = min(v[i] , dp[0][i-1]+1);
    }
    for(int i=n-2;i>=0;i--){
        dp[1][i] = min(v[i] , dp[1][i+1]+1);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans , min(dp[1][i] , dp[0][i]));
    }
    cout << ans << endl;

    return 0;
}
