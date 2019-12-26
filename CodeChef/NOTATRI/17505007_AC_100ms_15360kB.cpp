// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    while(cin >> n){

        if(!n)break;
        vector<ll>v(n);
        for(int i=0;i<n;i++)cin >> v[i];
        sort(v.begin() , v.end());

        ll ans = 0;

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                ans+=v.end()-upper_bound(v.begin()+j+1 , v.end() , v[i]+v[j]);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
