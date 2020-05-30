// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[105][105] , ar[105][105] , st;
int n , m;

ll f(int i , int j)
{
    if(i==n-1&&j==m-1)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll value = 1e18;
    if(i+1<n&&ar[i+1][j]>=st+i+j+1)value = min(value , f(i+1 , j)+ar[i+1][j]-(st+i+j+1));
    if(j+1<m&&ar[i][j+1]>=st+i+j+1)value = min(value , f(i , j+1)+ar[i][j+1]-(st+i+j+1));
    return dp[i][j] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> ar[i][j];
            }
        }
        ll ans = 1e18;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                st = ar[i][j] - i - j;
                if(st>ar[0][0])continue;
                memset(dp , -1 , sizeof(dp));
                ans = min(ans , f(0 , 0) + ar[0][0] - st);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
