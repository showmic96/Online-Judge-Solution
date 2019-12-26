// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 998244353;

int main(void)
{
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<ll>v1(n) , v2(n);
    vector<pair<ll , ll > > v;
    for(auto &x:v1)cin >> x;
    for(auto &x:v2)cin >> x;
    for(int i=1;i<=n;i++){
        v.push_back({(ll)i*(n-i+1)*v1[i-1] , v1[i-1]});
    }
    sort(v.begin() , v.end());
    sort(v2.begin() , v2.end());
    ll ans = 0;
    for(int i=0;i<v.size();i++){
        v[i].first%=MOD;
        v2[n-1-i]%=MOD;
        ans+=v[i].first*v2[n-1-i];
        ans%=MOD;
    }
    cout << ans << endl;
    return 0;
}
