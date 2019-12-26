#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(void)
{
    ll a;
    cin >> a;
    for(ll b=0;b<a;b++){
        ll c , d;
        cin >> c >> d;
        if(d%c==0)cout << c << " " << d << endl;
        else cout << -1 << endl;
    }
    return 0;
}
