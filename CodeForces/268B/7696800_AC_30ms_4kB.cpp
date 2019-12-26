// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a;
    cin >> a;
    ll ans = a;
    int d = 1;

    while(d<a){

        ans+=((a-d)*(d));
        d++;
    }

    cout << ans << endl;

    return 0;
}
