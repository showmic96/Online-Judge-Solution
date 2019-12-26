// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n , a , b , c;
    cin >> n >> a >> b >> c;

    if(n<a&&n<b)cout << 0 << endl;

    else if(a<=b-c){

        cout << n/a << endl;
    }

    else{
        ll ans = 0;
        if(n-c>=0)ans = (n-c)/(b-c);
        ans += (n-ans*(b-c))/a;
        //if(ans<0)cout << 0 << endl;
        cout << ans << endl;
    }
    return 0;
}
