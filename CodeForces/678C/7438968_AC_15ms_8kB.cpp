// In the name of Allah the Most Merciful

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a , ll b )
{
    if(a==0)return b;

    return gcd(b%a , a);
}

ll lcm(ll a , ll b)
{
    return (a*b)/gcd(a , b);
}

int main(void)
{
    ll n , a , b , p , q;

    cin >> n >> a >> b >> p >> q;

    ll ans1 = (n/a)*p;
    ll ans2 = (n/b)*q;
    ll ans3 = (n/lcm(a , b))*min(p, q);

    cout << ans1+ ans2 - ans3 << endl;

    return 0;
}
