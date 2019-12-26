// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(void)
{
    int n;

    cin >> n;

    set<ll>st;
    set<ll>:: iterator it;
    map<ll, ll>mp;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        st.insert(in);
        mp[in]++;
    }

    ll counter = 0;
    vector<ll>ans;
    int c = 1;

    for(it = st.begin();it!=st.end();it++){

        if(counter<3){counter+=mp[*it];ans.push_back(mp[*it]);}
        else break;

    }

    sort(ans.begin() , ans.end());

    if(ans.size()==3){

        cout << ans[2] << endl;
    }

    else if(ans.size()==2){

        if(ans[0]==1)cout << ((ans[1])*(ans[1]-1))/2 << endl;
        else cout << ans[1] << endl;
    }

    else cout << (ans[0]*(ans[0]-1)*(ans[0]-2))/6 << endl;

    return 0;
}
