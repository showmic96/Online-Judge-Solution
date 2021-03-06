// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e5+9;
int dp[MAX+9] , sum[MAX+9] , ar[MAX+9] , best[MAX+9];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , m , k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)cin >> ar[i];
    sort(ar+1 , ar+n+1);
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1]+ar[i];
    }
    for(int i=1;i<=k;i++)best[i] = i;
    for(int i=0;i<m;i++){
        int in1 , in2;
        cin >> in1 >> in2;
        best[in1] = min(best[in1] , in1-in2);
    }
    for(int i=1;i<=k;i++){
        dp[i] = sum[i];
        for(int j=1;j<=i;j++){
            dp[i] = min(dp[i] , dp[i-j]+sum[i]-sum[i-best[j]]);
        }
    }
    cout << dp[k] << endl;
    return 0;
}
