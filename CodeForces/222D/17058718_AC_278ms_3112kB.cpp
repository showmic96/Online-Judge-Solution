// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v1 , v2;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , x;
    cin >> n >> x;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        v1.push_back(in);
    }

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        v2.push_back(in);
    }

    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());
    v2.push_back(1e18);

    ll mi = 1e18;

    for(int i=0;i<n;i++){

        ll now = v1[i];

        int idx = upper_bound(v2.begin() , v2.end() , x-v1[i]-1) - v2.begin();
        now+=v2[idx];

        if(now>=x)mi = min(mi , now);
    }

    int i = 0 , j = n-1 , counter = 0;

    while(i<n&&j>=0){

        if(v1[i]+v2[j]>=mi){

            counter++;
            i++;
            j--;
        }
        else i++;
    }

    cout << 1 << ' ' << counter << '\n';

    return 0;
}
