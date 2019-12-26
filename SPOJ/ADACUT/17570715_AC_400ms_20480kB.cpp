// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 3e5+9;
const ll INF = 1e18+9;

ll sum[MAX] , v[MAX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)cin >> v[i+1];
    sort(v+1 , v+n+1);
    for(int i=1;i<=n;i++)sum[i]+=sum[i-1]+v[i];

    ll ans = 1e18;
    for(int i=1;i<=n;i++){

        ll temp = v[i]*(ll)(n-i);
        ans = min(ans , sum[n]-v[i]-temp);
    }

    cout << ans << endl;

    return 0;
}
