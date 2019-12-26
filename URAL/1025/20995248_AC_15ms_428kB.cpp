// In the name the Allah the Most Merciful.
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
    sort(v.begin() , v.end());
    ll ans = 0;
    for(int i=0;i<=v.size()/2;i++){
        ans+=(v[i]+2)/2;
    }
    cout << ans << endl;
    return 0;
}
