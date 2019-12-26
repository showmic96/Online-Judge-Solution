// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll d , k , a , b , t;
    cin >> d >> k >> a >> b >> t;
    if(k>=d){

        cout << min(d*a , d*b) << endl;
    }

    else{

        ll ans = 0;
        ans+= min(k*a , k*b);
        d-=k;
        ll r = (double)(ceil((d+k)/k));
        //cout << r << endl;
        ll min1 = (r-1)*t + (r-1)*k*a;

        min1 = min(min1 , (r-1)*k*b);

        d-=(r-1)*k;

        ll min2 = t + a*d;
        min2 = min(min2 , b*d);

        ans+=min1;
        ans+=min2;
        cout << ans << endl;
    }
    return 0;
}
