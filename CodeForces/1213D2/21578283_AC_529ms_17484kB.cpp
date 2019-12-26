// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 100005;
map<ll , ll>ar , val;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , k;
    cin >> n >> k;
    vector<ll>v(n);
    for(auto &x:v)cin >> x;
    sort(v.begin() , v.end());
    ll ans = 1e18;
    for(int i=0;i<n;i++){
        ll now = v[i] , cnt = 0;
        while(now){
            ar[now]++;
            val[now]+=cnt;
            if(ar[now]>=k){
                ans = min(ans , val[now]);
            }
            now/=2;
            cnt++;
        }
    }
    cout << ans << endl;

    return 0;
}
