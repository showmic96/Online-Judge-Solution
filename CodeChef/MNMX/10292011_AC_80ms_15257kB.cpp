// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        ll n;
        cin >> n;

        ll mi = 1e17;

        for(int i=0;i<n;i++){

            ll in;
            cin >> in;

            mi = min(mi , in);
        }

        ll ans = mi * (n-1);

        cout << ans << endl;
    }

    return 0;
}
