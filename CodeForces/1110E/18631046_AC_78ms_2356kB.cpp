// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int>c(n) , t(n);
    for(auto &x : c)cin >> x;
    for(auto &x : t)cin >> x;

    vector<int>v1 , v2;

    for(int i=1;i<n;i++){
        v1.emplace_back(c[i]-c[i-1]);
    }
    for(int i=1;i<n;i++){
        v2.emplace_back(t[i]-t[i-1]);
    }
    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());

    bool check = true;
    if(c[0]!=t[0])check = false;
    if(c[n-1]!=t[n-1])check = false;

    for(int i=0;i<v1.size();i++){
        if(v1[i]!=v2[i])check = false;
    }

    if(check)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
