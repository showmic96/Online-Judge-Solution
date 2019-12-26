// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

map<char , ll>mp;
void pre()
{
    mp['B'] = 1;
    mp['U'] = 10;
    mp['S'] = 100;
    mp['P'] = 1000;
    mp['F'] = 10000;
    mp['T'] = 100000;
    mp['M'] = 1000000;
}
bool ins(string ar)
{
    set<char>st;
    map<char , int> fr;
    st.insert(ar[0]);fr[ar[0]]++;
    for(int i=1;i<ar.size();i++){
        st.insert(ar[i]);
        fr[ar[i]]++;
        if(mp[ar[i-1]]>mp[ar[i]])return false;
    }
    for(auto it:st){
        if(fr[it]>9)return false;
    }
    return true;
}
bool dec(string ar)
{
    set<char>st;
    map<char , int> fr;
    st.insert(ar[0]);fr[ar[0]]++;
    for(int i=1;i<ar.size();i++){
        st.insert(ar[i]);
        fr[ar[i]]++;
        if(mp[ar[i-1]]<mp[ar[i]])return false;
    }
    for(auto it:st){
        if(fr[it]>9)return false;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    pre();
    int t;
    cin >> t;
    while(t--){
        string ar;
        cin >> ar;
        if(ins(ar)==true||dec(ar)==true){
            ll ans = 0;
            for(int i=0;i<ar.size();i++){
                ans+=mp[ar[i]];
            }
            cout << ans << endl;
        }
        else{
            cout << "error" << endl;
        }
    }
    return 0;
}
