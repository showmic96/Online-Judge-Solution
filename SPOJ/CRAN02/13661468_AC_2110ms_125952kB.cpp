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

        ll ans = 0 , sum = 0;

        map<ll , ll>mp;
        set<ll>st;
        set<ll>::iterator it;

        int n;
        cin >> n;
        mp[0] = 1;

        for(int i=0;i<n;i++){

            ll in;
            cin >> in;

            sum+=in;

            st.insert(sum);
            st.insert(in);

            mp[sum]++;
        }

        for(it=st.begin();it!=st.end();it++){

            ll temp = mp[*it];

            ans+= temp*(temp-1) >> 1;
        }

        cout << ans << endl;
    }
    return 0;
}
