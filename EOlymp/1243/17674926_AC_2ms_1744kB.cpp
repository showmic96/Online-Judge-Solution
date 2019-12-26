// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        vector<ll>v(n);

        for(int i=0;i<n;i++)cin >> v[i];
        ll ans = v[0];

        for(int i=1;i<n;i++){

            ll t = __gcd(v[i] , ans);
            ans = ans*v[i];
            ans/=t;
        }
        cout << ans << endl;
    }

    return 0;
}
