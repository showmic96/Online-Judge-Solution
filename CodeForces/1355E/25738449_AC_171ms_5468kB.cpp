// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , a , r , m;
vector<ll>v;

ll f(ll x)
{
    ll a1 = 0 , r1 = 0;
    for(int i=0;i<v.size();i++){
        if(x>=v[i])a1+=x-v[i];
        else r1+=v[i]-x;
    }
    ll m1 = min(a1 , r1);
    return (a1-m1)*a+(r1-m1)*r+m1*min(a+r , m);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> a >> r >> m;
    for(int i=0;i<n;i++){
        ll in;
        cin >> in;
        v.push_back(in);
    }
    ll l = 0 , r = 2e9 , t = 100;
    while(t--){
        ll l1 = (2*l+r)/3;
        ll l2 = (l+2*r)/3;
        if(f(l1)<f(l2))r = l2;
        else l = l1;
    }
    ll ans = 1e18;
    for(ll i=max(0LL , l-10);i<r+10;i++){
        ans = min(ans , f(i));
    }
    cout << ans << endl;

    return 0;
}
