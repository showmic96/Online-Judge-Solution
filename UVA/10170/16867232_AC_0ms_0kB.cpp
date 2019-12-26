// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll in1 , in2;
    while(cin >> in1 >> in2){

        ll hi = 2e8 , low = 1 , mid , ans = -1 , t = 100;
        while(t--){

            mid = (hi+low)/2;

            ll temp = (2*in1+(mid-1LL))*mid;
            temp/=2;

            if(temp>=in2){

                ans = mid;
                hi = mid-1;
            }
            else low = mid+1;
        }

        cout << ans+in1-1LL << endl;
    }
    return 0;
}
