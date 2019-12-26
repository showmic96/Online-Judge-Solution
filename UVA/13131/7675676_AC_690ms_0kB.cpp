// In the name of Allah the most Merciful .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll t;

    cin >> t;

    while(t--){

        ll a , b;
        cin >> a >> b;
        ll lim = sqrt(a) , ans = 0;;

        for(ll i=1;i<=lim;i++){

            if(a%i==0){

                if(i%b!=0)ans+=i;
                if((a/i)%b!=0)if(i!=a/i)ans+=a/i;
            }
        }
        if(a==1&&b!=1)ans=1;

        cout << ans << endl;

    }

    return 0;
}
