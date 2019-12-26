// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a[7] , b , c , ans, mod = 1e9+7;

    cin >> a[1] >> a[2] >> b;


    for(int i=3;i<7;i++){

        a[i] = a[i-1] - a[i-2];
    }

    a[0] = a[6];

    b = b%6;

    ans = a[b];
    cout << (ans%mod+mod)%mod << endl;

    return 0;
}
