// In the name of Allah the most Merciful .


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void)
{
    ll mi[12];

    for(ll i=0;i<12;i++){

        mi[i] = (ll)pow(2 , i);
    }

    ll t , ans=0 , in , temp;

    cin >> t;

    while(t--){

        cin >> in;
        ans = 0;

        for(ll i=11;i>=0;i--){

            temp = in%mi[i];
            in/=mi[i];
            ans+=in;

            in = temp;
        }

        cout << ans << endl;
    }

    return 0;

}
