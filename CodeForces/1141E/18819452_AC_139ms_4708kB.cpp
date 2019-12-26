// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 150005;
ll sum[400005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll h , n;
    cin >> h >> n;
    vector<ll>v(n+1);
    vector<ll>temp;
    for(int i=1;i<=n;i++)cin >> v[i];
    ll ans = -1 , mi = 1e18;
    for(int i=1;i<=n;i++){
        v[i]+=v[i-1];
        mi = min(mi , v[i]);
        if(v[i]+h<=0){ans = i;break;}
    }
    if(ans!=-1)cout << ans << endl;
    else if(v[n]>=0)cout << -1 << endl;
    else{
        ll lim = (h+mi+abs(v[n])-1)/abs(v[n]);
        ll ans = 1e18;
        for(ll i1=max(0LL , (ll)lim-100);i1<lim+100;i1++){
            ll temp = i1;
            ll tot = temp*v[n];
            ll now = n*temp;
            bool found = false;
            for(int i=1;i<=n;i++){

                if(v[i]+tot+h<=0){found=true;now+=i;break;}
            }
            if(found==true)ans = min(ans, now);
        }
        cout << ans << endl;
    }
    return 0;
}
