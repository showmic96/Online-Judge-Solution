// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int>v;
    multiset<int>st;
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        v.push_back(in);
    }
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        st.insert(in);
    }
    st.insert(1e9);
    for(int i=0;i<n;i++){
        auto it1 = st.upper_bound(-1);
        auto it2 = st.upper_bound(n-v[i]-1);
        if(*it2==1e9){
            cout << (v[i]+(*it1))%n << " ";
            st.erase(it1);
        }
        else{
            int t1 = (v[i]+(*it1))%n;
            int t2 = (v[i]+(*it2))%n;
            if(t1<t2){
                cout << t1 << " ";
                st.erase(it1);
            }
            else{
                cout << t2 << " ";
                st.erase(it2);
            }
        }
    }
    return 0;
}
