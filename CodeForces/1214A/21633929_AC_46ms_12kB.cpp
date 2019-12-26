// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , d , e;
    cin >> n >> d >> e;
    ll ans = n;
    for(ll i=0;i<=n;i++){
        ll t1 = i*d;
        if(t1>n)break;
        ll t2 = n-i*d;
        t2 = t2/(5LL*e);
        t2 = t2*(5LL*e);
        ans = min(ans , n-t1-t2);
    }
    cout << ans << endl;
    return 0;
}
