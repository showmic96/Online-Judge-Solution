// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[1000005] , n , k , v[1000005];
string ar;

int f(int i)
{
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1)return dp[i];
    int value = 1e7;
    if(i+k>n)value = min(value, f(i+k)+v[n]-v[i]);
    else {
        value = min(value , f(i+k)+(int)(ar[i+k-1]=='0')+v[i+k-1]-v[i]);
        value = min(value, f(n)+v[n]-v[i]);
    }
    return dp[i] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> k >> ar;
        if(n==1){
            cout << 0 << endl;
        }
        else{
            v[0] = 0;
            for(int i=0;i<ar.size();i++){
                int now = ar[i] - '0';
                v[i+1] = v[i] + now;
            }
            for(int i=0;i<=n;i++)dp[i] = -1;
            int ans = v[n]-v[0];
            for(int i=1;i<=n;i++){
                ans = min(ans , f(i)+v[i-1]-v[0]+(ar[i-1]=='0'));
            }
            cout << ans << endl;
        }
    }

    return 0;
}
