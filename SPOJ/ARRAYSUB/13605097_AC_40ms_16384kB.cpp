// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int>v;

    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v.push_back(in);
    }

    int k;
    cin >> k;

    multiset<int>st;
    multiset<int>::iterator it;

    for(int i=0;i<k;i++)st.insert(v[i]);
    for(int i=0;i<n;i++){

        it = st.end();it--;
        if(i>0)cout << " ";
        cout << *it;

        st.insert(v[i+k]);
        it = st.find(v[i]);
        st.erase(it);

        if(k+i>=n)break;
    }

    cout << endl;

    return 0;
}
