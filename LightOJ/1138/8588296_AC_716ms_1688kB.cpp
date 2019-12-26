// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll zero(ll x)
{
    ll five = 5 , ans = 0;
    while(five<=x){

        ans+= (x/five);
        five*=5;
    }

    return ans;
}

int main(void)
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){

        ll n;
        cin >> n;
        ll hi = 1e18 , low = 0 , mid , ans = -1;

        int c = 200;

        while(c--){

            mid = (hi+low)/2;

            ll temp = zero(mid);

            if(temp==n)ans=mid;

            if(temp>=n){

                hi = mid - 1;
            }

            else {

                low = mid + 1;
            }
        }

        printf("Case %d: ",i+1);
        if(ans==-1)cout << "impossible" << endl;
        else cout << ans << endl;
    }
    return 0;
}
