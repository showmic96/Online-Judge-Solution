// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll value(ll x)
{
//cout << x << " ";
    ll sum = 0;
    while(x!=0){

        sum+=x%10;
        x/=10;
    }
    //cout << sum << endl;
    return sum;
}

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        ll n;
        cin >> n;

        int c = 45;

        ll n_temp = n;
        ll store = 0;

        while(c--){

            if(value(n_temp)+(n_temp)==n){

                store = n_temp;
            }

            n_temp--;
        }

        cout << store << endl;
    }

    return 0;
}
