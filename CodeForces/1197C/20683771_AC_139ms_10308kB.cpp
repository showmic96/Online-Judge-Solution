// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v1 , v2;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n , k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        ll in;
        cin >> in;
        v1.push_back(in);
    }
    for(int i=1;i<n;i++){
        v2.push_back(v1[i]-v1[i-1]);
    }
    sort(v2.begin() , v2.end());
    reverse(v2.begin() , v2.end());
    ll tot = 0;
    for(int i=0;i<k-1;i++){
        tot+=v2[i];
    }
    cout << v1[n-1]-v1[0]-tot << endl;

    return 0;
}
