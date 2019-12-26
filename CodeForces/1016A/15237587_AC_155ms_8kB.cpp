// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , m;
    cin >> n >> m;

    ll pre = 0 , cur = 0;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;

        cur+=in;

        cout << cur/m - pre/m << " ";
        pre = cur;
    }

    return 0;
}
