// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n , a , b;
    cin >> n >> a >> b;

    ll ar[n];

    for(int i=0;i<n;i++)cin >> ar[i];

    ll ans = 0;

    for(int i=0;i<n-1;i++){

        ll temp = ar[i+1] - ar[i];
        ans+=min(temp*a , b);
    }

    cout << ans << endl;

    return 0;
}
