#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    ll a;cin >> a;
    for(ll b=0;b<a;b++){
        ll c , d , e;
        cin >> c >> d >> e;
        printf("Case %lld: ",b+1);
        ll k=d+e;
        while(k>c)k-=c;
        //if(d+e>c)cout << d+e-c << endl;
        cout << k << endl;
    }
    return 0;
}
