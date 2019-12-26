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

        ll n , f;
        cin >> n >> f;

        vector<ll>v;
        map<ll , ll>mp;
        set<ll>st;

        for(int i=0;i<n;i++){

            ll in;
            cin >> in;
            v.push_back(in);
            st.insert(in);
            mp[in]++;
        }

        sort(v.begin() , v.end());

        ll counter = 0;

        for(set<ll>::iterator it = st.begin();it!=st.end();it++){

            ll now = *it;
            ll temp = mp[now];

            ll t1 = temp;
            ll t2 = temp-1;

            if(t1%2==0)t1/=2;
            else t2/=2;

            counter+=t1*t2;
        }

        for(int i=0;i<n;i++){

            ll now = v[i];

            while(now<=10000000000){

                now*=f;
                counter+=upper_bound(v.begin()+i , v.end() , now)-lower_bound(v.begin()+i , v.end() , now);
                //now*=f;
            }
        }

        cout << counter << endl;
    }

    return 0;
}
