// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cnt1 , cnt2 , cnt3 , x , y;

bool possible(ll v)
{
    ll temp = (x*y)/(__gcd(x,y));
    ll total = v - (v/x + v/y - v/temp);


    ll t1 = v/y - v/temp;
    ll t2 = v/x - v/temp;
    ll t3 = v/temp;

    //cout << cnt1 << " " << t1 << " " << cnt2 << " " << t2 << " " << total << endl;

    if(total+t1+t2<cnt1+cnt2)return false;

    if(t1>=cnt1){

        if(t2+total>=cnt2)return true;
        return false;
    }

    if(t2>=cnt2){

        if(t1+total>=cnt1)return true;
        return false;
    }

    total-=cnt2 - t2;
    total-=cnt1 - t1;

    if(total>=0)return true;
    return false;
}

int main(void)
{
    //cnt1 = 3 , cnt2 = 1 , x = 2 , y = 3;
    //if(possible(5)==true)cout << "YES" << endl;
    //else cout << "NO" << endl;
    cin >> cnt1 >> cnt2 >> x >> y;

    ll hi = 1e12 , low = 0 , mid , t = 200 , ans = 0;

    while(t--){

        mid = (hi+low)/2;

        if(possible(mid)==true){

            ans = mid;
            hi = mid-1;
        }
        else low = mid+1;
    }

    cout << ans << endl;

    return 0;
}
