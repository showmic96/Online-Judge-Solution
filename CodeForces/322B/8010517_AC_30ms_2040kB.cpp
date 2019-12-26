// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a , a+3);
    a[1]-=a[0];
    a[2]-=a[0];
    ll ans = a[0];
    ans+=a[1]/3;
    ans+=a[2]/3;
    a[1] = a[1] % 3;
    a[2] = a[2] % 3;

    if(a[0]!=0){
        if(a[1]==2&&a[2]>=2)ans+=1;
    }

    cout << ans << endl;

    return 0;
}
