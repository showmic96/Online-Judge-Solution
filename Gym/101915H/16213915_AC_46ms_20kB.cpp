// In the name of Allah the Lord of the Worlds.

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

        int n , k;
        cin >> n >> k;

        vector<int>v;

        int ar[3];
        for(int i=0;i<n;i++){

            cin >> ar[0] >> ar[1] >> ar[2];
            sort(ar , ar+3);
            v.push_back(ar[0]);
            v.push_back(ar[1]);
        }

        sort(v.begin() , v.end());
        ll ans = 0;

        for(int i=0;i<k;i++)ans+=v[i];
        cout << ans << endl;
    }

    return 0;
}
