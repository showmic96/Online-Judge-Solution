// In the name of Allah the Lord of the Worlds.

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
        ll a , b , n , s;
        cin >> a >> b >> n >> s;
        ll t1 = s/n;
        t1 = t1*n;
        ll t2 = a*n;
        ll now = min(t1 , t2);
        ll req = s-now;
        if(req<=b)cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
