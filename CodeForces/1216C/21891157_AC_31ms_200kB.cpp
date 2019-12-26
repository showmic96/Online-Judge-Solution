// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[105][105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int a[12];
    set<int>st;
    map<int , int>mp;
    for(int i=0;i<12;i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    int c = 0;
    for(auto it:st){
        mp[it] = ++c;
    }
    for(int i=0;i<12;i+=4){
        for(int i1=mp[a[i]];i1<mp[a[i+2]];i1++){
            for(int j1=mp[a[i+1]];j1<mp[a[i+3]];j1++){
                ar[i1][j1] = i+1;
            }
        }
    }
    bool found = false;
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            if(ar[i][j]==1)found = true;
        }
    }
    if(found)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
