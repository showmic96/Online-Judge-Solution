// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n , m;
    while(cin >> n >> m){

        double dis;
        cin >> dis;

        long double t = (long double)n/m;

        ll c , d;
        bool check = true;

        for(ll i=1;;i++){


            d = i;
            c = (ll)(d*t);

            while(n*d>=m*c)c++;

            long double temp = (long double)c/d;


            if(temp-t<=dis){

                printf("%lld %lld\n",c , d);
                check = false;
                break;
            }
        }
    }
    return 0;
}
