// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<ll>v(n);
    for(auto &x:v)cin >> x;
    ll sum = 0 , mx = 0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        mx = max(v[i] , mx);
    }
    if(sum%2)cout << "NO" << endl;
    else{
        if(mx>sum/2)cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}
