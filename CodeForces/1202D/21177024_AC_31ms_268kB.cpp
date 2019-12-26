// In the name the Allah the Most Merciful.

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
        ll n , idx = 0;
        cin >> n;
        for(ll i=1;;i++){
            ll temp = i*(i-1LL)/2LL;
            if(temp>n)break;
            idx = i;
        }
        string ans = "1";
        for(int i=0;i<idx-2;i++){
            ans+="3";
        }
        n-=idx*(idx-1LL)/2LL;
        for(int i=0;i<n;i++){
            ans+="1";
        }
        ans+="337";
        cout << ans << endl;
    }
    return 0;
}
