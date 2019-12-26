// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll a)
{
    ll sum = 1;
    for(int i=0;i<a;i++){
        sum*=2;
    }

    //cout << sum << endl;

    return sum;
}

ll p(ll a)
{
    ll sum = 1;
    ll d = 1;
    while(f(d)<=a){

        sum+=f(d);
        d++;
    }

    return sum;
}

int main(void)
{
    ll t;
    cin >> t;
    while(t--){

        ll in;
        cin >> in;

        ll sum = ((1+in)*in/2);
        //cout << sum << endl;
        cout << sum - 2*p(in) << endl;
    }
    return 0;
}
