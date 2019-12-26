// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n;
    cin >> n;
    if(n==1)cout << 1 << endl;
    else if(n==2)cout << 2 << endl;
    else {

        if(n%2)cout << (ll)n*(n-1)*(n-2) << endl;
        else if(n%3)cout << (ll)n*(n-1)*(n-3) << endl;
        else cout << (ll)(n-1)*(n-2)*(n-3) << endl;
    }

    return 0;
}
