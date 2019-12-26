// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 998244353;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    ll ans = 0;
    for(int i=0;i<n;i++){
        string ar;
        cin >> ar;
        ll now = 0;
        for(int j=0;j<ar.size();j++){
            now*=100;
            now+=ar[j]-'0';
            now%=MOD;
        }
        ans+=now*((ll)n*10LL+(ll)n);
        ans%=MOD;
    }
    cout << ans << endl;

    return 0;
}
