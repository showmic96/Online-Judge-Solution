// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , ar[1000000+9];

int main(void)
{
    cin >> n;

    ar[0]=0;
    for(int i=1;i<=n;i++){cin >> ar[i];ar[i]+=ar[i-1];}

    ll counter = 1 , ans;

    if(ar[n]%3!=0)cout << 0 << endl;

    else{

        counter = 0;
        ans = 0;
        ll u = ar[n]/3;
        ll v = 2*u;

        for(int i=1;i<n;i++){

            if(ar[i]==v)ans+=counter;
            if(ar[i]==u)counter++;

        }

        cout << ans << endl;
    }
    return 0;
}
