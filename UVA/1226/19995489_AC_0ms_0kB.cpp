// In the name of Allah the Most Merciful.

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
        string ar;
        ll ans = 0 , n;
        cin >> n >> ar;
        for(int i=0;i<ar.size();i++){
            ans*=10;
            ans+=ar[i]-'0';
            ans%=n;
        }
        cout << ans << endl;
    }

    return 0;
}
