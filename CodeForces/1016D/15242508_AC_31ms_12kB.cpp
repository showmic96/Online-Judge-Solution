// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , m;
    cin >> n >> m;
    vector<ll>v1 , v2;

    ll x1 = 0 , x2 = 0;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        v1.push_back(in);
        x1^=in;
    }

    for(int i=0;i<m;i++){

        ll in;
        cin >> in;
        v2.push_back(in);
        x2^=in;
    }

    if(x1==x2){
        cout << "YES" << endl;
        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(i==j&&i==0)cout << (x1^v1[0]^v2[0]) << " ";
                else if(i==0)cout << v2[j] << " ";
                else if(j==0)cout << v1[i] << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }
    }
    else cout << "NO" << endl;

    return 0;
}
