#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a , b , c , in , ans1 = 0 , ans2 = 0;
map<ll ,ll>maping;

int main(void)
{
    cin >> a;

    for(ll i=1;i<=a;i++){

        cin >> in;
        maping[in] = i;
    }

    cin >> b;

    for(ll i=0;i<b;i++){

        cin >> in;

        ans1+=maping[in];
        ans2+=a - maping[in] + 1;
    }

    cout << ans1 << " " << ans2 << endl;


    return 0;
}
