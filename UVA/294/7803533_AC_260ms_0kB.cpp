// In the name of Allah the most Merciful .

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        ll in1 , in2 , store , ans , hi = 0 , counter = 0;
        cin >> in1 >> in2;

        for(ll i=in1;i<=in2;i++){

            ll lim = sqrt(i);
            counter = 2;

            for(ll j=2;j<=lim;j++){

                if(i%j==0){

                    if(j!=i/j)counter+=2;
                    else counter+=1;
                }
            }

            if(counter>hi){hi = counter;ans = i;}
        }

        if(in1==1&&in2==1)hi=1;

        cout <<"Between " << in1 << " and " << in2 << ", " << ans << " has a maximum of " << hi << " divisors." << endl; //Between 1 and 10, 6 has a maximum of 4 divisors.
    }

    return 0;
}
