// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    scanf("%d",&n);

    vector<ll>v;
    set<ll>st;

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        st.insert(in);
    }

    for(set<ll>::iterator it = st.begin();it!=st.end();it++)v.push_back(*it);
    ll mx = 0;

    for(int i=0;i<v.size();i++){

        for(ll j=2;j*v[i]<=2000000;j++){

            ll temp = v[i]*j;
            vector<ll>::iterator it = lower_bound(v.begin() , v.end() , temp);
            ll idx = it - v.begin();

            mx = max(mx , v[idx-1]%v[i]);
            if(it==v.end())break;
        }
    }

    printf("%lld\n",mx);

    return 0;
}
