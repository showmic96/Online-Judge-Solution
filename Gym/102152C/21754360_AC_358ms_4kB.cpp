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
        ll n , m;
        cin >> n >> m;
        if((n+m)%2==0)cout << 12 << endl;
        else cout << 2 << endl;
    }

    return 0;
}
