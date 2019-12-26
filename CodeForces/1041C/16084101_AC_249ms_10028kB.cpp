// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<ll , ll> A , pair<ll , ll> B)
{
    return A.first < B.first;
}

int ans[100005*5];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , m , d;
    cin >> n >> m >> d;

    set<pair<ll , ll> > st;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        st.insert(make_pair(in , i+1));
    }

    int counter = 1;

    while(st.empty()==false){

        auto it = st.begin();
        while(it!=st.end()){

            ans[it->second] = counter;
            int pos = it->first;
            st.erase(it);
            it = st.lower_bound({pos+d+1,0});
        }
        counter++;
    }

    cout << counter-1 << endl;

    for(int i=1;i<=n;i++){

        if(i>1)cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
