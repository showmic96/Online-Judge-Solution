// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<string, ll>mp;
    set<string>st;
    set<string>:: iterator it;

    vector<ll>v;

    ll n , k;
    cin >> n >> k;

    for(int i=0;i<n;i++){

        string ar;
        ll in;
        cin >> ar >> in;

        mp[ar]+=in;
        st.insert(ar);
    }

    for(it=st.begin();it!=st.end();it++){

        string ar = *it;
        v.push_back(mp[ar]);
    }

    sort(v.begin() , v.end());
    reverse(v.begin() , v.end());
    ll ans = 0;

    for(int i=0;i<min((ll)v.size() , k);i++)ans+=v[i];
    cout << ans << endl;

    return 0;
}
