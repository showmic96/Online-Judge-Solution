// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        set<ll>st;
        set<ll>::iterator it;
        map<ll , int>mp;

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);
            st.insert(in);
            mp[in]++;
        }

        ll sum = 0;

        for(it = st.begin();it!=st.end();it++){

            ll temp = *it;

            sum+= 1.00*(temp+1)*ceil(1.00*mp[temp]/(temp+1));
        }

        printf("Case %d: %lld\n",++c , sum);
    }
    return 0;
}
