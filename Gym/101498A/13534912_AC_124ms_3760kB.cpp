// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

map<int , int>mp;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int mx = 0 , ans = 1e9;mp.clear();

        for(int i=0;i<n;i++){
            string ar;int br;

            cin >> ar >> br;

            mp[br]++;

            if(mp[br]==mx){

                ans = min(ans , br);
            }

            if(mp[br]>mx){

                mx = mp[br];
                ans = br;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
