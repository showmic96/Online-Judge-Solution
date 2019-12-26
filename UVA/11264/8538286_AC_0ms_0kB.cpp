// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , a[10101];
ll dp[10101];

ll f(ll i , ll value)
{

    if(i>=n)return 0;

    if(dp[i]!=-1)return dp[i];

    ll v1 = 0 , v2 = 0;
    if(value+a[i]<a[i+1])v1 = f(i+1 , a[i]+value) + 1;
    v2 = f(i+1 , value);

    return dp[i] = max(v1 , v2);
}

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        memset(dp , -1 , sizeof(dp));
        cin >> n;

        for(int i=0;i<n;i++)cin >> a[i];
        a[n] = 1e18;
        cout << f(1 , 1)+1 << endl;
    }
    return 0;
}
