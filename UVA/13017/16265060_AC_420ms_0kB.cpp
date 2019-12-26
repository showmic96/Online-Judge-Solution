// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , tc = 0;

    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        multiset<ll>st;

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            st.insert(in);
        }

        ll ans = 0;

        for(int i=0;i<n-1;i++){

            ll a = *st.begin();
            st.erase(st.begin());
            ll b = *st.begin();
            st.erase(st.begin());

            ans+=a+b;
            st.insert(a+b);
        }

        printf("%lld\n",ans);
    }

    return 0;
}
