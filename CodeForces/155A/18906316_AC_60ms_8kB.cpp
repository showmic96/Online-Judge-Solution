// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &x:v)cin >> x;
    int mx = v[0] , mi = v[0] , ans = 0;
    for(auto x:v){
        if(x>mx||x<mi)ans++;
        mx = max(mx , x);
        mi = min(mi , x);
    }
    cout << ans << endl;
    return 0;
}
