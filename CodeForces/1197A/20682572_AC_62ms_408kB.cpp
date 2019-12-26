// In the name of Allah the Most Merciful.

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
        int n;
        cin >> n;
        vector<int>v(n);
        for(auto &x:v)cin >> x;
        sort(v.begin() , v.end());
        ll t1 = v[n-2];
        ll rem = n-2;
        cout << min(rem , t1-1) << endl;
    }

    return 0;
}
