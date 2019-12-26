#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(void)
{
    ll a , b , c , d , e  , f , g;
    cin >> a;
    for(b=0;b<a;b++){
        cin >> e;
        c=4;d=4;
        if(e==1)cout << 1 << endl;
        else{
            for(ll x =1 ;x < e-1;x++){
                c=2*c;
                d+=c;
            }
            cout << d << endl;
        }
    }

    return 0;
}
