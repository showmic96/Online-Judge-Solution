// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , m;
vector<ll>v1 , v2 , v;
set<ll>st;

void ff(int i , ll f , ll s)
{
    if(i==m){

        if(f==s&&f>0){

            st.insert(f);
        }

        return ;
    }

    ff(i+1 , f+v2[i] , s);
    ff(i+1 , f , s+v2[i]);
    ff(i+1 , f , s);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        v1.push_back(in);
    }

    for(int i=0;i<m;i++){

        ll in;
        cin >> in;
        v2.push_back(in);
    }

    ff(0 , 0 , 0);


    for(set<ll>::iterator it = st.begin(); it!=st.end();it++)v.push_back(*it);

    set<ll>ans;


    for(int i=0;i<n;i++){
        ans.insert(v1[i]);
        for(int j=0;j<v.size();j++){

            ans.insert((ll)2*v[j]+v1[i]);
        }
    }

    for(set<ll>::iterator it = ans.begin();it!=ans.end();it++)cout << *it << endl;

    return 0;
}
