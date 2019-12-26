// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a ;string ar;
    cin >> a >> ar;

    ll x = 0 , mx = 0;

    for(int i=0;i<a;i++){

        if(ar[i]=='I')x++;
        else x--;
        if(x>mx)mx=x;
    }

    cout << mx << endl;

    return 0;
}
