// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll p(ll value  , ll pwr)
{
    ll ans = 1;

    for(int i=0;i<pwr;i++){

        ans*=value;
    }

    return ans;
}

int main(void)
{
    ll a , b , n;
    cin >> a >> b >> n;

    for(int i=0;i<=1000;i++){

        if(a*p(i , n)==b){

            cout << i << endl;
            return 0;
        }

        else if(a*p(-i , n)==b){

            cout << -i << endl;
            return 0;
        }
    }

    cout << "No solution" << endl;

    return 0;
}
