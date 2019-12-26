// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n , k , p;
    cin >> n >> k >> p;

    vector<ll>v1 , v2;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        v1.push_back(in);
    }

    for(int i=0;i<k;i++){

        ll in;
        cin >> in;
        v2.push_back(in);
    }

    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());

    ll ans = 1e19;

    for(int i=0;i<k;i++){

        ll counter = 0;

        for(int j=0;j<n;j++){

            if(i+j>=k){

                counter = 1e19;
                break;
            }

            counter=max(counter , (abs(v1[j] - v2[i+j]) + abs(v2[i+j] - p)));
        }

        ans = min(ans , counter);
    }

    cout << ans << endl;

    return 0;
}
