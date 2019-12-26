// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , k;
    while(cin >> n >> k){

        long double ans = 0;
        for(ll i=n-k+1;i<=n;i++){

            ans+=log10((long double)i);
        }
        for(ll i=1;i<=k;i++){
            ans-=log10((long double)i);
        }

        ll a = floor(ans);

        cout << a+1 << endl;
    }

    return 0;
}
