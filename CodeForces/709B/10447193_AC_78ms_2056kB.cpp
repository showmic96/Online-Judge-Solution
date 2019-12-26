// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n ,a;
    cin >> n >> a;

    vector<ll>v;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        v.push_back(in);
    }

    sort(v.begin() , v.end());
    
    if(n==1){
        
        cout << 0 << endl;
        return 0;
    }

    ll t[4];

    t[0] = abs(v[0] - a) + abs(v[n-2]-v[0]);
    t[1] = abs(v[1] - a) + abs(v[n-1]-v[1]);
    t[2] = abs(v[n-2] - a) + abs(v[n-2]-v[0]);
    t[3] = abs(v[n-1] - a) + abs(v[n-1]-v[1]);


    sort(t , t+4);

    cout << t[0] << endl;

    return 0;
}
