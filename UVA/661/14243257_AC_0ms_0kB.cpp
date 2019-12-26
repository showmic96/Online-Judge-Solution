// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , m , c , tc = 0;
    while(cin >> n >> m >> c){

        if(n==0&&m==0&&c==0)break;
        vector<ll>v;
        v.push_back(0);

        for(int i=0;i<n;i++){

            ll in;
            cin >> in;
            v.push_back(in);
        }

        ll mx = 0 , sum = 0;
        for(int i=0;i<m;i++){

            ll in;
            cin >> in;
            sum+=v[in];
            v[in] = -v[in];

            mx = max(sum , mx);
        }

        cout << "Sequence " << ++tc << endl;
        if(mx>c)cout << "Fuse was blown." << endl;
        else cout << "Fuse was not blown." << endl << "Maximal power consumption was " << mx << " amperes." << endl;
        cout << endl;
    }

    return 0;
}
